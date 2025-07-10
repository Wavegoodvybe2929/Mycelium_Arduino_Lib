use pyo3::prelude::*;
use ndarray::Array1;
use mycelium_dsp::{filters, spike_detection::{detect_spikes, DetectionParams}};
use mycelium_lang::{word_extraction, complexity};

#[pyfunction]
fn py_bandpass_filter(data: Vec<f32>, low: f32, high: f32) -> Vec<f32> {
    let arr = Array1::from(data);
    filters::bandpass_filter(&arr, low, high).to_vec()
}

#[pyfunction]
fn py_detect_spikes(data: Vec<f32>, window: usize, delta: f32) -> Vec<usize> {
    let arr = Array1::from(data);
    let params = DetectionParams { window, delta };
    detect_spikes(&arr, &params)
}

#[pyfunction]
fn py_shannon_entropy(seq: &str) -> f64 {
    complexity::shannon_entropy(seq)
}

#[pyfunction]
fn py_lz_complexity(seq: &str) -> usize {
    complexity::lz_complexity(seq)
}

#[pymodule]
fn mycelium(_py: Python, m: &PyModule) -> PyResult<()> {
    m.add_function(wrap_pyfunction!(py_bandpass_filter, m)?)?;
    m.add_function(wrap_pyfunction!(py_detect_spikes, m)?)?;
    m.add_function(wrap_pyfunction!(py_shannon_entropy, m)?)?;
    m.add_function(wrap_pyfunction!(py_lz_complexity, m)?)?;
    Ok(())
}
