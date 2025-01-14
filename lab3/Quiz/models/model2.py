import torch
import torch.nn as nn


class Model2(torch.nn.Module):
    def __init__(self):
        super(Model2,self).__init__()
        self.conv1=nn.Conv2d(3,96,kernel_size=7,stride=1,padding=3)
        self.conv2=nn.Conv2d(96,128,kernel_size=5,stride=1,padding=2)
        self.conv3=nn.Conv2d(128,256,kernel_size=3,stride=1,padding=1)
        self.maxpool=nn.MaxPool2d(kernel_size=3,stride=2)
        self.fn1=nn.Linear(256*3*3,4096)
        self.fn2=nn.Linear(4096,4096)
        self.fn3=nn.Linear(4096,10)
        self.lrn1=nn.LocalResponseNorm(size=96)
        self.lrn2=nn.LocalResponseNorm(size=128)
        self.lrn3=nn.LocalResponseNorm(size=256)


    def forward(self,x):
        x = self.lrn1(self.maxpool(torch.relu(self.conv1(x))))
        x = self.lrn2(self.maxpool(torch.relu(self.conv2(x))))
        x = self.lrn3(self.maxpool(torch.relu(self.conv3(x))))
        x = x.view(x.size(0), -1)
        x=self.fn1(x)
        x=nn.Dropout(p=0.5)(x)
        x=self.fn2(x)
        x=nn.Dropout(p=0.5)(x)
        x=self.fn3(x)

        return x