import torch

class EnvContextModel(torch.nn.Module):
    def __init__(self, input_dim, hidden_dim, output_dim):
        super(EnvContextModel, self).__init__()
        self.fc1 = torch.nn.Linear(input_dim, hidden_dim)
        self.tanh = torch.nn.Tanh()
        self.fc2 = torch.nn.Linear(hidden_dim, output_dim)

    def forward(self, x):
        x = self.tanh(self.fc1(x))
        x = self.fc2(x)
        return x

def load_context_model(model_path):
    model = EnvContextModel(input_dim=64, hidden_dim=128, output_dim=32)
    model.load_state_dict(torch.load(model_path, map_location='cpu'))
    model.eval()
    return model
