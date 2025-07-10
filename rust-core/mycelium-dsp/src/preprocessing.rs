use ndarray::Array1;

pub fn normalize(data: &Array1<f32>) -> Array1<f32> {
    let min = data.fold(f32::INFINITY, |a, &b| a.min(b));
    let max = data.fold(f32::NEG_INFINITY, |a, &b| a.max(b));
    if (max - min).abs() < f32::EPSILON {
        return data.clone();
    }
    data.mapv(|x| (x - min) / (max - min))
}
