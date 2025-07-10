use anyhow::Result;

pub fn parse_message(line: &str) -> Result<Option<f32>> {
    if line.starts_with("S:") {
        let value_str = &line[2..];
        let value: f32 = value_str.trim().parse()?;
        Ok(Some(value))
    } else {
        Ok(None)
    }
}
