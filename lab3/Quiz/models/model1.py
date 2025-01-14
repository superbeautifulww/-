import torch
import torch.nn as nn


class Mode11(nn.Module):
    def __init__(self):
        super(Mode11,self).__init__()
        self.conv1=nn.Conv2d(3,6,kernel_size=5,stride=1,padding=0)
        self.conv2=nn.Conv2d(6,16,kernel_size=5,stride=1,padding=0)
        self.maxpool=nn.MaxPool2d(kernel_size=2,stride=2)
        self.fc1=nn.Linear(16*5*5,120)
        self.fc2 = nn.Linear(120,84)
        self.fc3 = nn.Linear(84,10)

    def forward(self,x):
        x=self.maxpool(torch.tanh(self.conv1(x)))
        x=self.maxpool(torch.tanh(self.conv2(x)))
        x=x.view(x.size(0),-1)
        x=torch.tanh(self.fc1(x))
        x=torch.tanh(self.fc2(x))
        x=self.fc3(x)
        return x


