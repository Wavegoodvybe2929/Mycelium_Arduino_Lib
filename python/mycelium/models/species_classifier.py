import torch

class SpeciesClassifier(torch.nn.Module):
    def __init__(self, input_dim, hidden_dim, num_classes):
        super(SpeciesClassifier, self).__init__()
        self.fc1 = torch.nn.Linear(input_dim, hidden_dim)
        self.relu = torch.nn.ReLU()
        self.fc2 = torch.nn.Linear(hidden_dim, num_classes)

    def forward(self, x):
        x = self.relu(self.fc1(x))
        x = self.fc2(x)
        return x

def load_species_classifier(model_path):
    model = SpeciesClassifier(input_dim=64, hidden_dim=128, num_classes=4)
    model.load_state_dict(torch.load(model_path, map_location='cpu'))
    model.eval()
    return model
