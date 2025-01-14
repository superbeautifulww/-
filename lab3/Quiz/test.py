if __name__ == '__main__':
    import torch
    import torch.nn as nn
    import torch.optim as optim
    from torch.utils.data import DataLoader

    from torchvision import transforms
    from torchvision.datasets import ImageFolder


    #超参数设置
    batch_size = 4
    lr = 0.001
    epoch = 40
    print_every = 1000  # 输出损失的频率

    #加载数据集
    train_path = "D:/CVML/RS32/train"
    val_path = "D:/CVML/RS32/val"
    test_path = "D:/CVML/RS32/test"
    out_dir = "./model33"

    data_transform = {
    "train": transforms.Compose([
        transforms.ToTensor(),
        transforms.Normalize([0, 0, 0], [1, 1, 1])]),
    "test": transforms.Compose([
        transforms.ToTensor(),
        transforms.Normalize([0, 0, 0], [1, 1, 1])])}

    trainset = ImageFolder(train_path, transform=data_transform["train"])
    valset = ImageFolder(val_path, transform=data_transform["test"])
    testset = ImageFolder(test_path, transform=data_transform["test"])

    train_loader = torch.utils.data.DataLoader(trainset,batch_size=batch_size,
                                            shuffle=True,num_workers=4)
    val_loader = torch.utils.data.DataLoader(valset,batch_size=batch_size,
                                         shuffle=True,num_workers=4)
    test_loader = torch.utils.data.DataLoader(testset,batch_size=batch_size,
                                         shuffle=True,num_workers=4)
    dtype = torch.float32  #使用float作为数据类型

    USE_GPU = True

    if USE_GPU and torch.cuda.is_available():
        device = torch.device('cuda')
    else:
        device = torch.device('cpu')

    print('using device:', device)

    import train
    from models.model1 import Mode11
    from models.model2 import Model2

    from models.model3 import Model3

    from models.model4 import Model4

    net = Model4()
    net = net.to(device)

    criterion = nn.CrossEntropyLoss()
    optimizer = optim.SGD(net.parameters(), lr=lr, momentum=0.9, weight_decay=5e-4)
    scheduler = torch.optim.lr_scheduler.StepLR(optimizer, step_size=20, gamma=0.5)

    import time
    tic = time.time()
    train.train_val(train_loader, val_loader, net, criterion, optimizer, epoch, print_every, device, scheduler,
            output_dir=out_dir)
    
    toc = time.time()
    print(toc - tic)

    # 加载模型参数
    ckp = "D:/CVML/lab3/Quiz/model33/epoch039.pth"
    pretrained_dict = torch.load(ckp)
    net.load_state_dict(pretrained_dict["net"])

    # 测试
    train.predict(test_loader, net, criterion, device)
