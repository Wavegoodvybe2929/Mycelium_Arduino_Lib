use ndarray::Array1;

pub struct DetectionParams {
    pub window: usize,
    pub delta: f32,
}

pub fn detect_spikes(data: &Array1<f32>, params: &DetectionParams) -> Vec<usize> {
    let mut spikes = Vec::new();
    let n = data.len();

    for i in params.window..(n - params.window) {
        let neighborhood: f32 = data.slice(s![(i - params.window)..(i + params.window)]).mean().unwrap();
        let value = data[i].abs();

        if (value - neighborhood).abs() > params.delta {
            spikes.push(i);
        }
    }

    spikes
}
