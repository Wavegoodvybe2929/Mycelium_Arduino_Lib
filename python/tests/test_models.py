from mycelium.models import bitnet_decoder, env_context, species_classifier
import torch

def test_bitnet_decoder_load(tmp_path):
    # Create dummy model state
    model = bitnet_decoder.BitNetDecoder(128, 256, 64)
    model_path = tmp_path / "bitnet.pth"
    torch.save(model.state_dict(), model_path)
    loaded = bitnet_decoder.load_decoder(str(model_path))
    assert isinstance(loaded, bitnet_decoder.BitNetDecoder)

def test_env_context_load(tmp_path):
    model = env_context.EnvContextModel(64, 128, 32)
    model_path = tmp_path / "context.pth"
    torch.save(model.state_dict(), model_path)
    loaded = env_context.load_context_model(str(model_path))
    assert isinstance(loaded, env_context.EnvContextModel)

def test_species_classifier_load(tmp_path):
    model = species_classifier.SpeciesClassifier(64, 128, 4)
    model_path = tmp_path / "classifier.pth"
    torch.save(model.state_dict(), model_path)
    loaded = species_classifier.load_species_classifier(str(model_path))
    assert isinstance(loaded, species_classifier.SpeciesClassifier)
