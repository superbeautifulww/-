import torch
import torch.nn as nn


class ResidualBlock(nn.Module):
    def __init__(self, channels_in, channels_out):
        super(ResidualBlock, self).__init__()
        self.conv1 = nn.Conv2d(channels_in, channels_out, kernel_size=3, stride=1, padding=1)
        self.bn1 = nn.BatchNorm2d(channels_out)
        self.relu = nn.ReLU(inplace=True)
        self.conv2 = nn.Conv2d(channels_out, channels_out, kernel_size=3, stride=1, padding=1)
        self.bn2 = nn.BatchNorm2d(channels_out)
        if channels_in != channels_out:
            self.downsample = nn.Sequential(
                nn.Conv2d(channels_in, channels_out, kernel_size=1, stride=1),
                nn.BatchNorm2d(channels_out)
            )
        else:
            self.downsample = nn.Identity()

    def forward(self, x):
        identity = self.downsample(x)
        out = self.conv1(x)
        out = self.bn1(out)
        out = self.relu(out)
        out = self.conv2(out)
        out = self.bn2(out)
        out += identity
        out = self.relu(out)
        return out

class ConvLayers(nn.Module):
    def __init__(self, conv_arch):
        super(ConvLayers, self).__init__()
        layers = []
        channels_in = 3
        for (num_convs, channels_out) in conv_arch:
            for i in range(num_convs):
                layers.append(ResidualBlock(channels_in, channels_out))
                channels_in = channels_out
            layers.append(nn.MaxPool2d(kernel_size=2, stride=2))
        self.conv_layers = nn.Sequential(*layers)

    def forward(self, x):
        return self.conv_layers(x)

class Model4(nn.Module):
    def __init__(self):
        super(Model4,self).__init__()
        self.conv_arch = ((2, 64), (3, 128), (3, 256), (3, 512))
        self.conv_layers = ConvLayers(self.conv_arch)
        self.fn1=nn.Linear(512*2*2,4090)
        self.fn2=nn.Linear(4090,1000)
        self.fn3=nn.Linear(1000,10)


    def forward(self,x):
        x = self.conv_layers(x)

        # 将卷积层的输出展平
        x = x.view(x.size(0), -1)
        # 添加全连接层
        x = torch.relu(self.fn1(x))
        x = nn.Dropout(p=0.5)(x)  # 使用nn.Dropout
        x = torch.relu(self.fn2(x))
        x = nn.Dropout(p=0.5)(x)  # 使用nn.Dropout
        x = self.fn3(x)
        return x
