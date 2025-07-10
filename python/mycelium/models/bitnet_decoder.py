import torch

class BitNetDecoder(torch.nn.Module):
    def __init__(self, input_dim, hidden_dim, output_dim):
        super(BitNetDecoder, self).__init__()
        self.fc1 = torch.nn.Linear(input_dim, hidden_dim)
        self.relu = torch.nn.ReLU()
        self.fc2 = torch.nn.Linear(hidden_dim, output_dim)

    def forward(self, x):
        x = self.relu(self.fc1(x))
        x = self.fc2(x)
        return x

def load_decoder(model_path):
    model = BitNetDecoder(input_dim=128, hidden_dim=256, output_dim=64)
    model.load_state_dict(torch.load(model_path, map_location='cpu'))
    model.eval()
    return model
