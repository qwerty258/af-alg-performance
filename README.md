Search `af_alg_register_type` in linux kernel code v6.5.9, it seems that only "aead", "hash", "rng" and "skcipher" are registered. So compression type will not be found in `bind()`.
