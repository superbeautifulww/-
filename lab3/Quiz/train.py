import torch
import torch.nn as nn
import torch.optim as optim
from torch.utils.data import DataLoader
from torchvision import transforms
from torchvision.datasets import ImageFolder
import os
from models.model1 import Mode11
from models.model2 import Model2

from models.model3 import Model3
from models.model4 import Model4

def train_val(loader_train, loader_val, model, criterion, optimizer, epochs, print_every, device,
              scheduler,
              output_dir=None):
    best_val = 0
    train_loss = 0
    val_loss = 0
    train_correct = 0
    train_total = 0
    val_correct = 0
    val_total = 0
    for epoch in range(epochs):
        print('Epoch: %d' % epoch)
        for batch_idx, (inputs, targets) in enumerate(loader_train):
            model.train()
            inputs, targets = inputs.to(device), targets.to(device)
            #######################################################################
            # TODO: Implement training of LeNet.                                  #
            #######################################################################
            # *****START OF YOUR CODE (DO NOT DELETE/MODIFY THIS LINE)*****

            optimizer.zero_grad()
            outputs = model(inputs)
            loss = criterion(outputs, targets)
            loss.backward()
            optimizer.step()

            train_loss += loss.item()
            _, predicted = outputs.max(1)
            train_total += targets.size(0)
            train_correct += predicted.eq(targets).sum().item()
        train_loss /= (batch_idx + 1)
        train_acc = 100. * train_correct / train_total
        print(f'training Loss: {train_loss:.3f}|Acc: {train_acc:.3f}%({train_correct}/{train_total})')



            # *****END OF YOUR CODE (DO NOT DELETE/MODIFY THIS LINE)*****
            #######################################################################
            #                           END OF YOUR CODE                          #
            #######################################################################
        scheduler.step()
        with torch.no_grad():
            for val_idx, (inputs, targets) in enumerate(loader_val):
                model.eval()
                inputs, targets = inputs.to(device), targets.to(device)
                #######################################################################
                # TODO: Implement testing of LeNet.                                   #
                #######################################################################
                # *****START OF YOUR CODE (DO NOT DELETE/MODIFY THIS LINE)*****
                outputs = model(inputs)
                loss = criterion(outputs, targets)

                val_loss += loss.item()
                _, predicted = outputs.max(1)
                val_total += targets.size(0)
                val_correct += predicted.eq(targets).sum().item()

                
                # *****END OF YOUR CODE (DO NOT DELETE/MODIFY THIS LINE)*****
                #######################################################################
                #                           END OF YOUR CODE                          #
                #######################################################################
            print('val Loss: %.3f | Acc: %.3f%%' % (val_loss / (val_idx + 1), 100. * val_correct / val_total))
        # Save checkpoint.
        acc = 100. * val_correct / val_total
        if acc > best_val and output_dir is not None:
            print('Saving..')
            state = {
                'net': model.state_dict(),
                'acc': acc,
                'epoch': epoch,
            }
            if not os.path.exists(output_dir):
                os.mkdir(output_dir)
            torch.save(state, os.path.join(output_dir, 'epoch%.3d.pth' % epoch))
            best_val = acc
        train_loss = 0
        val_loss = 0
    return


def predict(test_loader, model, criterion, device):
    r"""
    You can save the model file in output_ Under dir
    """
    test_loss = 0
    correct = 0
    total = 0
    with torch.no_grad():
        for batch_idx, (inputs, targets) in enumerate(test_loader):
            model.eval()
            inputs, targets = inputs.to(device), targets.to(device)
            #######################################################################
            # TODO: Implement testing of LeNet.                                   #
            #######################################################################
            # *****START OF YOUR CODE (DO NOT DELETE/MODIFY THIS LINE)*****

            outputs = model(inputs)  # 前向传播
            loss = criterion(outputs, targets)  # 计算损失

            test_loss += loss.item()
            _, predicted = outputs.max(1)
            total += targets.size(0)
            correct += predicted.eq(targets).sum().item()

            
            
            # *****END OF YOUR CODE (DO NOT DELETE/MODIFY THIS LINE)*****
            #######################################################################
            #                           END OF YOUR CODE                          #
            #######################################################################
        print('testing Loss: %.3f | Acc: %.3f%%' % (test_loss / (batch_idx + 1), 100. * correct / total))

