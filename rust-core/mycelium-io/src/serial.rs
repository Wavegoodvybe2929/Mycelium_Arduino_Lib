use anyhow::{Result, Context};
use serialport::prelude::*;
use std::io::{BufRead, BufReader};
use std::time::Duration;

pub fn read_serial(port_name: &str, baud_rate: u32) -> Result<()> {
    let port = serialport::new(port_name, baud_rate)
        .timeout(Duration::from_millis(1000))
        .open()
        .context("Failed to open serial port")?;

    let reader = BufReader::new(port);

    for line in reader.lines() {
        let line = line?;
        println!("Received: {}", line);
    }

    Ok(())
}
