import os
import time
import csv
import matplotlib.pyplot as plt
import numpy as np

classes = ['Waters', 'Forest', 'CultivateLand', 'River', 'Highway', 'Pylon', 'SwimmingPool', 'TennisCourt',
           'BasketballCourt', 'FootballField']

def gen_map(root):
    #Get the mapping table of the category
    name2label = {}
    for name in sorted(os.listdir(os.path.join(root))):
        name = name[1:]
        if name not in name2label.keys():
            name2label[name] = len(name2label.keys())
    return name2label

def gen_csv(root, filename, name2label):
    #Return the images and labels list from the csv file
    images = []
    images += glob.glob(os.path.join(root, '*/*.jpg'))
    np.random.seed(0)
    np.random.shuffle(images)  #Randomly sort all elements of the sequence
    
    with open(os.path.join(filename), mode='w', newline='') as file:
        writer = csv.writer(file)
        for img in images:
            #Get the category name of the photo
            class_name = img.split("\\")[-2][1:]
            writer.writerow([img, name2label[class_name]])

def load_data(filename):
    
    with open(os.path.join(filename,'train.csv')) as file:
        reader = csv.reader(file)
        images, labels = [], []
        for img, label in reader:
            img = plt.imread(img).astype("float32")
            #--------------------------------------------------
            #Store the imported images and labels in the images and labels list
            images.append(img)
            labels.append(label)
            pass
            
            #--------------------------------------------------
    images = np.array(images)
    labels = np.array(labels).astype(int)
    return images, labels


def visualize_samples(classes, X, Y):
    num_classes = len(classes)  
    samples_per_class = 7  
    for y, cls in enumerate(classes):  
        idxs = np.flatnonzero(Y == y)
        idxs = np.random.choice(idxs, samples_per_class, replace=False)  
        for i, idx in enumerate(idxs):  
            plt_idx = i * num_classes + y + 1  
            plt.subplot(samples_per_class, num_classes, plt_idx)  
            plt.imshow(X[idx].astype('uint8')) 
            plt.axis('off')
            if i == 0:
                plt.title(cls)  
    plt.show()  


def data_processing(Xtrain, Xval, Xtest):
    Xtrain = np.reshape(Xtrain, (Xtrain.shape[0], -1))
    Xval = np.reshape(Xval, (Xval.shape[0], -1))
    Xtest = np.reshape(Xtest, (Xtest.shape[0], -1))
    # Preprocessing: subtract the mean image
    
    # first: compute the image mean based on the training data
    mean_image = np.mean(Xtrain, axis=0)
    # print(mean_image[:10]) # print a few of the elements
    '''
    plt.figure(figsize=(4,4))
    plt.imshow(mean_image.reshape((32,32,3)).astype('uint8')) # visualize the mean image
    plt.show()
    '''
    # second: subtract the mean image from train and test data
    Xtrain -= mean_image
    Xval -= mean_image
    Xtest -= mean_image

    # third: append the bias dimension of ones (i.e. bias trick) so that our SVM
    # only has to worry about optimizing a single weight matrix W.
    #Xtrain = np.hstack([Xtrain, np.ones((Xtrain.shape[0], 1))])
    #Xval = np.hstack([Xval, np.ones((Xval.shape[0], 1))])
    #Xtest = np.hstack([Xtest, np.ones((Xtest.shape[0], 1))])

    return Xtrain, Xval, Xtest
