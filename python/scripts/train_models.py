import torch
from mycelium.models.bitnet_decoder import BitNetDecoder
from mycelium.models.env_context import EnvContextModel
from mycelium.models.species_classifier import SpeciesClassifier

def train_decoder():
    model = BitNetDecoder(128, 256, 64)
    # Add your dataset and training loop here
    print("Training decoder...")

def train_context():
    model = EnvContextModel(64, 128, 32)
    # Add your dataset and training loop here
    print("Training context model...")

def train_classifier():
    model = SpeciesClassifier(64, 128, 4)
    # Add your dataset and training loop here
    print("Training species classifier...")

if __name__ == "__main__":
    train_decoder()
    train_context()
    train_classifier()
