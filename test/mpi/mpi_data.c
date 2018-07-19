#include "mpi_test.h"

/*
 * General inputs
 */

const char g_a6400_bin[800] = {
    0xc9,0x2e,0x20,0xb9,0x90,0x84,0x6a,0x10,
    0x37,0x59,0x47,0x36,0xfd,0x02,0xce,0x34,
    0xf1,0x77,0x6d,0x4c,0x01,0x9b,0x0d,0x31,
    0xc4,0xb5,0xbd,0xb0,0xdf,0x56,0x8e,0xa2,
    0x29,0x22,0x23,0xe7,0x0d,0x6d,0xad,0x39,
    0x2d,0x46,0x65,0x00,0xc8,0xd1,0x8c,0x1e,
    0xa2,0x1b,0x64,0x33,0x76,0x7c,0xc0,0xfa,
    0x6d,0x4e,0xd3,0x44,0xae,0x38,0xb6,0x84,
    0xc1,0x2a,0xb8,0xf0,0x6e,0xe4,0x4c,0x78,
    0x7e,0x49,0x9f,0xda,0x20,0x4c,0x4c,0xbb,
    0x83,0x54,0x39,0xca,0x93,0x82,0x7b,0x8f,
    0x74,0x49,0xcc,0xb6,0x24,0xec,0x1b,0x77,
    0x83,0x7f,0x6c,0xc1,0xd7,0xac,0x8f,0x8f,
    0x60,0x78,0x20,0xa9,0xbf,0x21,0x0d,0x38,
    0xfa,0x7a,0xf0,0xab,0xf8,0xca,0x93,0xbf,
    0x9f,0xbf,0xa2,0x79,0x24,0x6f,0xf3,0x6a,
    0xca,0x41,0xa2,0xbc,0xdf,0x67,0x4b,0x2e,
    0x58,0xe2,0xbe,0xe6,0xe1,0xe5,0x65,0xb2,
    0x79,0xe4,0x49,0x59,0x80,0xc8,0x71,0xbc,
    0x6b,0x29,0xec,0xa6,0x12,0x11,0xdd,0xef,
    0x99,0xc6,0x83,0xce,0x43,0xcd,0xdb,0xd1,
    0xb8,0x2a,0x47,0xb1,0xd6,0xd8,0xae,0xdb,
    0x36,0x2a,0xcd,0x86,0xaf,0x64,0x70,0xbe,
    0x5f,0x93,0x45,0xb4,0xcf,0xa7,0x44,0x26,
    0x4e,0x07,0x4a,0x60,0x27,0x5e,0x81,0xde,
    0x16,0x58,0x36,0x88,0xca,0x08,0x2b,0x5f,
    0x16,0x6b,0x2b,0xa8,0xed,0x6f,0xb2,0x3c,
    0x88,0xba,0x46,0xc9,0xa8,0xed,0x07,0x91,
    0x62,0x8a,0xba,0xb6,0xbc,0xc7,0x29,0x11,
    0x00,0xef,0x30,0x1a,0xf3,0x09,0x13,0xf1,
    0x9e,0x03,0xf2,0xd8,0xc1,0xbe,0x35,0x97,
    0x28,0x66,0xaa,0xf6,0x39,0xcd,0x76,0x53,
    0xf9,0x94,0x4d,0xa1,0xd1,0xcd,0x01,0x74,
    0xac,0xd4,0x28,0xb6,0x85,0x9a,0x7f,0x65,
    0xdf,0xae,0x0c,0x27,0x30,0xbe,0xc6,0x84,
    0xb0,0x8b,0x8c,0x68,0x7b,0x0c,0xa7,0xb4,
    0x7e,0x20,0x2c,0x93,0x98,0x50,0xb0,0x27,
    0x60,0x62,0x90,0x6d,0xd3,0x31,0x01,0x91,
    0x90,0xad,0xfa,0x85,0x83,0x88,0x2e,0xe4,
    0xf7,0x15,0x84,0xd3,0xb2,0xf8,0x66,0xad,
    0x72,0x18,0x02,0x8e,0xab,0xec,0x5a,0x69,
    0x09,0xdf,0xbc,0xac,0x7f,0x30,0x82,0xda,
    0x1b,0x6c,0x22,0xe8,0xfc,0xa6,0x4e,0xe2,
    0x54,0x4c,0x52,0xfb,0x90,0xa0,0x03,0x11,
    0xcd,0x1d,0x72,0x0a,0xaa,0x6b,0xed,0x75,
    0xd0,0x56,0xf8,0xf2,0x89,0x26,0x6a,0x4e,
    0x7d,0xd4,0x5b,0xdb,0xe5,0xce,0x97,0xe9,
    0x32,0x0a,0xe5,0xc8,0x86,0x0f,0xa2,0x13,
    0x9e,0xf6,0x21,0xf8,0x8d,0xb4,0x3e,0xe9,
    0xd1,0x99,0x4f,0x43,0x1d,0x49,0x92,0xd5,
    0x4b,0x60,0x7d,0xb8,0x85,0x99,0xc5,0x24,
    0x68,0x05,0xa0,0xee,0xe8,0xb6,0x9e,0xaf,
    0x0c,0x5f,0xc3,0xb9,0x2b,0xa1,0x76,0x05,
    0xa2,0xf1,0x1e,0xbf,0xea,0x4c,0x8c,0x49,
    0xe0,0x77,0xf7,0x89,0xbc,0x5e,0x13,0xb9,
    0xfa,0x09,0xe8,0xb6,0xb3,0x0e,0xd0,0x82,
    0x8d,0xe5,0x1b,0xe0,0xe0,0x4a,0xf4,0x32,
    0x81,0x6c,0x0b,0x00,0x96,0x57,0x5b,0xd3,
    0xd4,0x94,0x91,0xc7,0x3f,0xbf,0x1b,0x9b,
    0x27,0x92,0x58,0x7b,0x85,0x71,0x08,0x6e,
    0x23,0xf2,0xf6,0x8a,0x5b,0xfd,0x83,0x41,
    0xb2,0xf6,0x07,0xc6,0x87,0x00,0xa2,0x7d,
    0xcd,0x61,0x0f,0x9a,0xe9,0x72,0xdc,0xb3,
    0x4a,0x01,0x4b,0x46,0xcd,0xa6,0x8b,0xb8,
    0xb3,0x27,0x90,0xeb,0x7a,0xc4,0x76,0xbd,
    0xe9,0xc7,0xed,0xc2,0xbe,0x5f,0x2f,0xf1,
    0xf9,0x40,0xc7,0x43,0xbc,0xc8,0xa5,0x6f,
    0xe7,0x15,0x58,0xad,0x93,0xe1,0x95,0x15,
    0x55,0xb4,0xd6,0xf2,0xe0,0xd4,0x6e,0xaa,
    0xd6,0x3f,0x40,0xbf,0x6b,0x92,0xd2,0x34,
    0xfa,0x74,0xe1,0xa7,0xcb,0x2e,0xb7,0x60,
    0xab,0xdd,0x2c,0x6d,0xb1,0xea,0xee,0xa5,
    0x15,0x19,0xdd,0x97,0x2f,0x8c,0x58,0x9c,
    0xfb,0xe3,0x6e,0x33,0xc1,0xf2,0xea,0x96,
    0xc6,0xd7,0x2b,0x5f,0xaf,0x0e,0x37,0x52,
    0x84,0x82,0x59,0xfe,0xc3,0x78,0x43,0x22,
    0x01,0x30,0xc4,0xa7,0xc1,0x22,0x68,0x4d,
    0x4c,0x10,0xc0,0xeb,0x75,0x51,0x4c,0x60,
    0x1d,0xb8,0xa2,0x7b,0x97,0x15,0xd1,0x43,
    0xc2,0x9e,0x30,0x5a,0x5a,0x13,0xf6,0x21,
    0x68,0x62,0x90,0x46,0x7b,0x31,0x3a,0xd6,
    0x8d,0x5e,0x24,0x9b,0x40,0xd4,0x8a,0x88,
    0x3d,0x38,0x24,0x0c,0x52,0xc7,0x40,0x41,
    0x1d,0x51,0x4a,0x30,0xf1,0x76,0x40,0xfb,
    0xcf,0xd5,0xbb,0x82,0x4b,0xa5,0x78,0xff,
    0xa6,0x07,0xee,0x12,0xcb,0x99,0xc4,0x3f,
    0x11,0xe6,0x47,0x58,0x5a,0xec,0x12,0xda,
    0x7f,0xa5,0xe8,0x7a,0x50,0x03,0xe8,0xc7,
    0x63,0x9d,0x57,0x3f,0x8a,0x44,0x52,0x6c,
    0x4f,0x18,0xa5,0xc5,0x82,0x36,0x41,0x22,
    0xc0,0xe1,0x0d,0x02,0x80,0x3b,0xeb,0x1c,
    0x1c,0xaa,0x0a,0x44,0x6c,0x56,0xe7,0x22,
    0xee,0x93,0x3e,0x7d,0x26,0x2c,0x49,0xa6,
    0xc3,0x5e,0x5f,0x8a,0xd4,0x37,0x84,0xd2,
    0x1a,0xce,0x6c,0x2c,0xec,0xff,0x5d,0xdd,
    0xb9,0xcf,0x87,0x75,0x0c,0x93,0x01,0xef,
    0x49,0xea,0xff,0xc6,0xd4,0xfd,0xc1,0x70,
    0x38,0x36,0xbe,0xcc,0x40,0x02,0xa9,0x1c,
    0x6e,0xe9,0xa9,0xa4,0x02,0xb0,0xa2,0x02,
    0x73,0xf4,0x10,0xe9,0xa4,0x08,0xf9,0x05,
};

const char g_b6400_bin[800] = {
    0x2b,0x6c,0xc1,0x4a,0x42,0x7b,0x83,0x3f,
    0x58,0x3b,0x1f,0x5f,0xab,0x69,0x85,0x5e,
    0xd6,0x1a,0x0a,0xe3,0x51,0x8a,0x7e,0x51,
    0x74,0x3d,0x95,0x68,0xf0,0x5a,0x90,0x79,
    0x7e,0xda,0xfa,0xea,0xe6,0xfd,0xd2,0xc6,
    0xeb,0x40,0x1b,0x74,0x3b,0x8c,0x5a,0xd4,
    0x34,0xbf,0x41,0x89,0xe2,0xde,0x8d,0xed,
    0xab,0xdc,0xdf,0x93,0x79,0xab,0x71,0x69,
    0x2d,0x0f,0x3f,0x96,0x58,0xe9,0x2d,0xfe,
    0x07,0xd4,0xa0,0x5f,0x11,0x22,0x4c,0x35,
    0xc1,0x4b,0xc8,0x3b,0x03,0x44,0xb8,0xfe,
    0x35,0x29,0x43,0xa0,0x82,0xee,0x06,0xce,
    0x88,0x84,0x89,0xbf,0x6f,0xc0,0x25,0x6d,
    0xcb,0xec,0x02,0x0b,0x71,0x7c,0x36,0x9e,
    0x6e,0xa8,0x72,0x56,0x2f,0xa8,0x73,0x6d,
    0xee,0x14,0x13,0xd6,0xc6,0xdd,0x95,0x31,
    0xc7,0x36,0x4b,0x99,0x4c,0x27,0xb2,0x64,
    0x80,0xa4,0x32,0x8a,0x9b,0xb9,0xa4,0x40,
    0x4f,0xbe,0x77,0x26,0xc8,0x54,0x06,0x8e,
    0x10,0x8f,0x86,0x33,0x8b,0xd5,0xf1,0xa4,
    0x53,0x4f,0xad,0xd1,0xd1,0x59,0x72,0xef,
    0xfc,0xcb,0x0b,0x90,0xe5,0x75,0xfd,0x81,
    0x53,0x48,0x0d,0x19,0x91,0x39,0x5f,0x49,
    0x0c,0x01,0xe8,0xb6,0xda,0xd9,0xf6,0x9a,
    0x17,0xd1,0xa3,0x10,0x17,0x0b,0x15,0xf7,
    0x57,0x59,0xa3,0xd2,0x1c,0x20,0x9b,0x15,
    0xc3,0x90,0x47,0x8e,0x05,0x39,0x87,0x32,
    0x3e,0xe0,0x22,0xd7,0x80,0x48,0x52,0xe1,
    0x7b,0xb1,0xa6,0x79,0x8d,0x21,0x97,0x6c,
    0x3c,0x5e,0xe4,0x31,0x26,0x44,0xb2,0x8b,
    0x6f,0x97,0x4e,0xac,0x6f,0xf1,0xd1,0xdb,
    0x83,0x44,0x26,0xd0,0xaa,0x86,0x18,0xac,
    0x95,0x05,0x4c,0x1c,0x1b,0x08,0x57,0x69,
    0xa8,0xc2,0x98,0xd1,0xe0,0xab,0xb4,0x99,
    0xe7,0x61,0xd1,0x1e,0x56,0xff,0x07,0xba,
    0xd4,0x3c,0x4a,0xe7,0x8c,0x53,0xa9,0x5a,
    0x8d,0xc2,0xa7,0x30,0xdf,0xc7,0xbb,0xb9,
    0xd7,0xc7,0x59,0x17,0x0c,0x83,0xb8,0x31,
    0xb1,0x64,0x07,0x37,0x08,0x1b,0xad,0xc6,
    0xf6,0x68,0x74,0x84,0x2d,0x21,0x85,0x8b,
    0x41,0x2b,0x05,0xd6,0x2e,0x3a,0xc5,0x66,
    0xd3,0x7b,0xd8,0x77,0x01,0x95,0xe3,0x48,
    0x26,0xfb,0x4c,0x35,0x1f,0xd1,0x07,0x54,
    0x72,0xf4,0xe7,0x43,0x25,0x5c,0x4b,0x1b,
    0x9e,0xc1,0xc9,0xd3,0xd6,0xae,0xdf,0xbd,
    0x25,0xc3,0xfb,0x77,0x72,0x59,0x2c,0x3d,
    0x29,0x35,0xe4,0x1c,0x28,0x07,0x91,0x3c,
    0xa9,0x57,0x5c,0x9c,0x9c,0x15,0x5d,0xe2,
    0xc7,0x0d,0xeb,0xf1,0x16,0x6c,0xc6,0xb0,
    0x6c,0xad,0xfb,0xbe,0x70,0x7d,0x7e,0xa3,
    0xeb,0x80,0x43,0x59,0xdb,0x08,0xd7,0x8b,
    0xe5,0x57,0xc5,0xbb,0xff,0xe7,0x5c,0x08,
    0x4b,0xe5,0xa0,0x19,0xbb,0x28,0x2a,0xcd,
    0xaa,0x20,0x1a,0xb8,0xf4,0x4b,0xed,0x03,
    0xda,0x09,0x0b,0xf8,0x3e,0x39,0xfa,0x05,
    0x67,0x33,0x1d,0x0a,0xfe,0x0d,0x31,0xaa,
    0x1c,0xcf,0x22,0xfb,0x40,0x7f,0xc2,0x29,
    0x58,0x4f,0x81,0x44,0x2b,0x56,0xfc,0x83,
    0x18,0x1a,0xf6,0x5a,0x14,0x88,0xa5,0xd6,
    0xa2,0x32,0xb4,0x77,0x7f,0x02,0x03,0x10,
    0x03,0x85,0xe7,0x23,0x6d,0x5e,0x3c,0xc4,
    0x56,0xce,0xe6,0x39,0x7c,0xa6,0x42,0x06,
    0x36,0xa9,0x84,0x8b,0x33,0xba,0x60,0x92,
    0xa2,0xf2,0xa4,0x5f,0x68,0xb8,0x8b,0x8f,
    0xfb,0x4c,0x9d,0xb8,0xba,0xa1,0x2d,0xc5,
    0x30,0x18,0xaa,0x74,0xea,0xcf,0x61,0xc8,
    0x26,0x6b,0xfb,0x94,0x33,0xfe,0x31,0xbe,
    0x22,0xc2,0x1c,0xaa,0x6a,0x16,0x58,0x3c,
    0x1d,0xc1,0x5d,0xe0,0x8e,0x82,0xe4,0xb7,
    0x34,0x13,0x79,0x4e,0xe9,0x50,0xb9,0x39,
    0x38,0x06,0x3e,0x50,0x26,0x41,0x24,0x3e,
    0x0b,0xf7,0x94,0xc5,0xd2,0xc4,0x69,0x0c,
    0x3f,0xf7,0x8b,0x29,0x5d,0xc2,0xdd,0x40,
    0xa4,0x46,0xa7,0x46,0x71,0xb0,0x93,0xb1,
    0x10,0xf1,0x8e,0x6e,0xb5,0xd2,0xa4,0x0b,
    0x54,0x5c,0x6a,0x5a,0x5a,0x60,0x49,0x4e,
    0x93,0xec,0xde,0x73,0xd6,0x37,0x30,0xb1,
    0xb3,0x4d,0x53,0x4c,0x9a,0xb0,0xaa,0xa2,
    0x5c,0x58,0xa0,0x7a,0x13,0x8b,0xae,0x78,
    0x84,0x9b,0x8e,0xdc,0xb1,0xac,0x36,0x0e,
    0x54,0x4a,0xe5,0xc0,0x88,0x0b,0x5f,0xc8,
    0xad,0xda,0x26,0x25,0x58,0x62,0xfc,0x03,
    0x65,0xdd,0x67,0x6a,0xff,0xd3,0x79,0xcb,
    0x0b,0x46,0xa0,0x15,0x50,0x27,0x00,0x10,
    0xb6,0x11,0xaf,0xfd,0x03,0x5d,0x77,0x5c,
    0xf8,0x11,0x65,0xc0,0x5e,0xda,0xe6,0x33,
    0x79,0xdc,0x0b,0x4d,0xbd,0x25,0xa7,0xa4,
    0xa1,0x82,0x0e,0x3e,0xe1,0x81,0x99,0x05,
    0x12,0x73,0xc8,0xfa,0x17,0xab,0x85,0x30,
    0x10,0x13,0xd6,0xb7,0x35,0x4f,0x34,0xec,
    0xcb,0xe4,0x9b,0x94,0x17,0x45,0x30,0xaa,
    0xd3,0x8d,0x59,0x06,0x6b,0xeb,0xbd,0xe9,
    0x57,0x86,0xe6,0x26,0x6e,0x57,0x4f,0x38,
    0xd0,0x77,0xe1,0x62,0xe5,0xd3,0x6a,0x20,
    0xe9,0x9b,0x34,0xfb,0xc6,0x0e,0x4f,0x3b,
    0xfb,0x08,0x61,0xa2,0x3d,0x68,0xd4,0x38,
    0x6a,0x8b,0x98,0x8c,0x56,0xa4,0xe7,0x27,
    0xe1,0x0a,0xd6,0xc8,0x47,0x74,0xad,0xc7,
    0x6d,0x6b,0xa6,0xcd,0xe1,0x60,0x32,0xcc,
    0xd3,0x0b,0x24,0xec,0x6b,0xaa,0xa6,0x28,
};

/*
 * Add data
 */

const char g_a8_b8_add_bin[1] = { 0xF4 };

const char g_a8_b256_add_bin[32] = {
    0x2b,0x6c,0xc1,0x4a,0x42,0x7b,0x83,0x3f,
    0x58,0x3b,0x1f,0x5f,0xab,0x69,0x85,0x5e,
    0xd6,0x1a,0x0a,0xe3,0x51,0x8a,0x7e,0x51,
    0x74,0x3d,0x95,0x68,0xf0,0x5a,0x91,0x42,
};

const char g_a1024_a512_add_bin[128] = {
    0xc9,0x2e,0x20,0xb9,0x90,0x84,0x6a,0x10,
    0x37,0x59,0x47,0x36,0xfd,0x02,0xce,0x34,
    0xf1,0x77,0x6d,0x4c,0x01,0x9b,0x0d,0x31,
    0xc4,0xb5,0xbd,0xb0,0xdf,0x56,0x8e,0xa2,
    0x29,0x22,0x23,0xe7,0x0d,0x6d,0xad,0x39,
    0x2d,0x46,0x65,0x00,0xc8,0xd1,0x8c,0x1e,
    0xa2,0x1b,0x64,0x33,0x76,0x7c,0xc0,0xfa,
    0x6d,0x4e,0xd3,0x44,0xae,0x38,0xb6,0x85,
    0x8a,0x58,0xd9,0xa9,0xff,0x68,0xb6,0x88,
    0xb5,0xa2,0xe7,0x11,0x1d,0x4f,0x1a,0xf0,
    0x74,0xcb,0xa7,0x16,0x95,0x1d,0x88,0xc1,
    0x38,0xff,0x8a,0x67,0x04,0x42,0xaa,0x19,
    0xac,0xa1,0x90,0xa8,0xe5,0x1a,0x3c,0xc8,
    0x8d,0xbe,0x85,0xaa,0x87,0xf2,0x99,0x57,
    0x9c,0x96,0x54,0xdf,0x6f,0x47,0x54,0xba,
    0x0d,0x0e,0x75,0xbd,0xd2,0xa8,0xa9,0xee,
};

const char g_a1024_a1024_add_bin[129] = {
    0x01,0x92,0x5c,0x41,0x73,0x21,0x08,0xd4,
    0x20,0x6e,0xb2,0x8e,0x6d,0xfa,0x05,0x9c,
    0x69,0xe2,0xee,0xda,0x98,0x03,0x36,0x1a,
    0x63,0x89,0x6b,0x7b,0x61,0xbe,0xad,0x1d,
    0x44,0x52,0x44,0x47,0xce,0x1a,0xdb,0x5a,
    0x72,0x5a,0x8c,0xca,0x01,0x91,0xa3,0x18,
    0x3d,0x44,0x36,0xc8,0x66,0xec,0xf9,0x81,
    0xf4,0xda,0x9d,0xa6,0x89,0x5c,0x71,0x6d,
    0x09,0x82,0x55,0x71,0xe0,0xdd,0xc8,0x98,
    0xf0,0xfc,0x93,0x3f,0xb4,0x40,0x98,0x99,
    0x77,0x06,0xa8,0x73,0x95,0x27,0x04,0xf7,
    0x1e,0xe8,0x93,0x99,0x6c,0x49,0xd8,0x36,
    0xef,0x06,0xfe,0xd9,0x83,0xaf,0x59,0x1f,
    0x1e,0xc0,0xf0,0x41,0x53,0x7e,0x42,0x1a,
    0x71,0xf4,0xf5,0xe1,0x57,0xf1,0x95,0x27,
    0x7f,0x3f,0x7f,0x44,0xf2,0x48,0xdf,0xe6,
    0xd4,
};

const char g_a264_a256_add_sign_bin[33] = {
    0xc8,0x64,0xf2,0x98,0xd6,0xf3,0xe5,0xa6,
    0x27,0x21,0xed,0xef,0xc6,0x05,0xcb,0x66,
    0xbc,0x85,0xf5,0xde,0xb5,0x99,0x72,0x24,
    0x92,0xf1,0x07,0xf3,0x2e,0x77,0x38,0x13,
    0x87,
};


/*
 * Sub data
 */

const char g_a8_b8_sub_bin[1] = {
    0x9e
};

const char g_a512_a256_sub_bin[64] = {
    0xc9,0x2e,0x20,0xb9,0x90,0x84,0x6a,0x10,
    0x37,0x59,0x47,0x36,0xfd,0x02,0xce,0x34,
    0xf1,0x77,0x6d,0x4c,0x01,0x9b,0x0d,0x31,
    0xc4,0xb5,0xbd,0xb0,0xdf,0x56,0x8e,0xa1,
    0x5f,0xf4,0x03,0x2d,0x7c,0xe9,0x43,0x28,
    0xf5,0xed,0x1d,0xc9,0xcb,0xce,0xbd,0xe9,
    0xb0,0xa3,0xf6,0xe7,0x74,0xe1,0xb3,0xc8,
    0xa8,0x99,0x15,0x93,0xce,0xe2,0x27,0xe2,
};

const char g_a1024_a256_sub_bin[128] = {
    0xc9,0x2e,0x20,0xb9,0x90,0x84,0x6a,0x10,
    0x37,0x59,0x47,0x36,0xfd,0x02,0xce,0x34,
    0xf1,0x77,0x6d,0x4c,0x01,0x9b,0x0d,0x31,
    0xc4,0xb5,0xbd,0xb0,0xdf,0x56,0x8e,0xa2,
    0x29,0x22,0x23,0xe7,0x0d,0x6d,0xad,0x39,
    0x2d,0x46,0x65,0x00,0xc8,0xd1,0x8c,0x1e,
    0xa2,0x1b,0x64,0x33,0x76,0x7c,0xc0,0xfa,
    0x6d,0x4e,0xd3,0x44,0xae,0x38,0xb6,0x84,
    0xc1,0x2a,0xb8,0xf0,0x6e,0xe4,0x4c,0x78,
    0x7e,0x49,0x9f,0xda,0x20,0x4c,0x4c,0xbb,
    0x83,0x54,0x39,0xca,0x93,0x82,0x7b,0x8f,
    0x74,0x49,0xcc,0xb6,0x24,0xec,0x1b,0x76,
    0xba,0x51,0x4c,0x08,0x47,0x28,0x25,0x7f,
    0x29,0x1e,0xd9,0x72,0xc2,0x1e,0x3f,0x04,
    0x09,0x03,0x83,0x5f,0xf7,0x2f,0x86,0x8d,
    0xdb,0x09,0xe4,0xc8,0x45,0x19,0x64,0xc8,
};

const char g_a264_a256_sub_sign_bin[33] = {
    0xc9,0xf7,0x4e,0xda,0x4a,0x14,0xee,0x7a,
    0x47,0x90,0xa0,0x7e,0x33,0xff,0xd1,0x03,
    0x26,0x68,0xe4,0xb9,0x4d,0x9c,0xa8,0x3e,
    0xf6,0x7a,0x73,0x6e,0x90,0x35,0xe5,0x30,
    0xcb,
};

/*
 * Mul data
 */

const char g_a6400_b6400_mul_bin[1600] = {
    0x22,0x20,0x36,0xdb,0x1b,0xcf,0x86,0x03,
    0x05,0x3a,0x22,0x29,0x26,0x58,0x6f,0xf5,
    0x62,0xcf,0x57,0x59,0xe1,0xd1,0x65,0x38,
    0x3e,0xe4,0x1b,0x50,0x5f,0xc2,0x99,0x8a,
    0x67,0x31,0xdd,0x7c,0xb8,0xac,0x39,0x10,
    0x40,0x02,0x6b,0xf0,0xe8,0x17,0x85,0x40,
    0xdd,0xb9,0xec,0x30,0xcb,0x98,0x8d,0xa1,
    0x76,0xcd,0x33,0xb2,0xee,0xb5,0xc6,0x10,
    0x06,0xb5,0x35,0xa4,0x88,0xe8,0x89,0x48,
    0xd0,0xb8,0x45,0x16,0x6f,0xdf,0xf3,0x83,
    0x07,0x3b,0x11,0xd6,0x8c,0x52,0x9d,0xc8,
    0x9a,0x06,0xa2,0x50,0xf4,0xb3,0xbc,0x71,
    0x19,0xb0,0x5f,0x4c,0xd5,0xc9,0x5e,0x19,
    0xfb,0xb0,0x4e,0xe7,0xce,0x1a,0xe0,0x03,
    0x74,0x3a,0x42,0x88,0x97,0xb5,0xc5,0x76,
    0x86,0x17,0xdd,0xf2,0x66,0x2e,0x19,0x89,
    0x84,0x16,0x7c,0x66,0x9a,0x32,0x47,0x4e,
    0x14,0x96,0x4c,0x1c,0x75,0xb0,0x34,0xd0,
    0x07,0xa9,0x78,0xa4,0xea,0x45,0x18,0xc5,
    0x26,0x57,0x40,0x8a,0x14,0x2b,0x60,0xaa,
    0x52,0xfe,0x3e,0xd2,0x16,0x36,0x70,0x14,
    0x85,0xe8,0x2e,0x87,0x53,0x33,0x7f,0x94,
    0x2f,0xf0,0x60,0xc4,0x24,0x29,0xc6,0xa8,
    0xab,0x3a,0x9f,0xcd,0xea,0x6a,0x27,0xf7,
    0xef,0x76,0xf2,0xd1,0x80,0x9a,0x18,0xbf,
    0xd4,0x3b,0x1f,0x5d,0xa7,0x4a,0x27,0x3f,
    0x51,0xc0,0x65,0x07,0xf5,0x94,0x5d,0x6f,
    0xa9,0xa2,0x73,0xdb,0x88,0x3a,0x86,0x36,
    0xf5,0xfe,0xb5,0x2e,0x35,0x3d,0xb1,0x5f,
    0x44,0x18,0xbf,0x94,0xc2,0xae,0x73,0x39,
    0x99,0xe7,0xed,0xf4,0xef,0x5e,0xa7,0xd9,
    0xb8,0xf0,0x0c,0xc6,0x75,0x74,0xe9,0xd9,
    0x86,0x04,0x12,0xcd,0x6b,0x5c,0xa8,0x5e,
    0xe1,0xbc,0x00,0xff,0xda,0x5c,0x2d,0x2f,
    0x74,0xae,0xc2,0xe0,0x36,0x3b,0x75,0x09,
    0xcb,0xf2,0x25,0x94,0xe0,0x08,0x12,0x05,
    0x99,0xd7,0xf8,0xd4,0xa9,0x38,0xe5,0xfb,
    0xc6,0xd8,0x13,0xfd,0xe2,0xb6,0x50,0x27,
    0x8c,0x43,0x9a,0xa8,0x55,0x6f,0xd5,0xd6,
    0x56,0x0a,0x27,0x4c,0x97,0x6e,0x2b,0x79,
    0xbc,0xa1,0x6f,0xab,0x4d,0x1c,0xa9,0x6a,
    0x6c,0xbb,0xd8,0xd6,0xcf,0x67,0xca,0x0a,
    0x79,0xa1,0x28,0x0f,0x14,0x71,0xda,0x2e,
    0x3e,0xe8,0xb7,0xe6,0x3b,0x61,0xba,0xbe,
    0xc8,0x34,0x93,0xff,0x44,0x25,0xc1,0xc4,
    0x34,0xcd,0x39,0x26,0xe1,0x8b,0xaf,0x03,
    0x96,0x2d,0x44,0x6d,0x44,0x05,0x07,0xc6,
    0xa4,0x9f,0x17,0xce,0xba,0xbb,0x57,0x74,
    0xa8,0x33,0x58,0x89,0x91,0xea,0xd6,0xed,
    0x9d,0xa9,0x64,0x5f,0xaf,0xd8,0xd7,0x0b,
    0xac,0x70,0x4d,0xdf,0xbf,0xc4,0x13,0x33,
    0x10,0xc8,0xa6,0xee,0xdb,0xe8,0x9b,0x8f,
    0xcd,0x1e,0xc5,0x18,0xc7,0x3d,0xc2,0x26,
    0x2f,0x0a,0x6f,0x6b,0xc5,0xf6,0xd1,0xd0,
    0x4f,0xa3,0x50,0xaa,0xd1,0xf0,0xd9,0x2a,
    0xcc,0xdc,0xf1,0x46,0x47,0x32,0x06,0x0a,
    0x6a,0x4a,0xc7,0xc9,0x20,0xbf,0x5f,0x73,
    0xdb,0xb8,0x43,0xee,0xb8,0x29,0x90,0x4b,
    0x9e,0x46,0x97,0x7d,0x0f,0xc5,0x49,0x23,
    0x74,0x7c,0xc0,0xde,0xbb,0x70,0x00,0xf0,
    0xb0,0xc1,0xc6,0x79,0xbf,0x92,0xa8,0x0e,
    0x44,0x1b,0x4b,0xf4,0xa0,0xae,0x21,0xa6,
    0x4b,0x60,0xd3,0xb7,0xf4,0x4f,0x60,0x74,
    0x13,0xe5,0xb3,0x08,0x33,0xa5,0xb7,0x5c,
    0x9e,0xbc,0x01,0x4c,0x7b,0x98,0x1c,0x1a,
    0xcf,0xf1,0xb0,0xba,0xfc,0xc1,0x6b,0xd0,
    0xc5,0x90,0xc0,0x9f,0x24,0x5c,0xab,0x89,
    0xc6,0x25,0xbc,0x03,0xfb,0x48,0x43,0xa5,
    0x97,0xd2,0x5b,0x87,0x86,0x13,0xf5,0x75,
    0x85,0x3f,0xc4,0xc5,0x8c,0xe6,0x8a,0x8d,
    0x30,0x41,0x30,0x6d,0x71,0x79,0x52,0xdf,
    0x3f,0xbb,0x3b,0xd2,0xe2,0x3c,0x60,0x4d,
    0xdf,0xc5,0xaf,0xe6,0x32,0xba,0x39,0xbc,
    0xda,0x0f,0x32,0x25,0x55,0xd8,0x48,0x06,
    0xc5,0x2c,0x35,0x83,0x19,0x09,0x90,0x1b,
    0x06,0x42,0x89,0x7e,0x8a,0xb7,0x12,0x67,
    0x30,0x4e,0x78,0xbe,0x30,0xbb,0x60,0xe3,
    0x2e,0xa1,0x66,0x45,0xf7,0xa0,0x4f,0x2d,
    0xc0,0xe6,0xcd,0x6a,0x98,0xb4,0xdf,0xa4,
    0x10,0x3d,0x26,0xc4,0x24,0x8c,0x45,0x8f,
    0x4d,0xb9,0xf6,0xa0,0x15,0xc5,0xbc,0x78,
    0x4b,0x66,0x7b,0x6e,0xb4,0x73,0xae,0x23,
    0x2e,0x31,0x74,0x87,0x9d,0x17,0xf6,0x6e,
    0x5f,0xcc,0xfa,0xc9,0x05,0xb2,0x62,0x81,
    0x0c,0xe4,0x96,0x02,0xa7,0xc0,0x78,0x51,
    0x93,0x8f,0xd5,0x00,0xf1,0xd8,0x37,0x6b,
    0x0e,0xa5,0x37,0xd6,0x43,0x46,0x01,0x29,
    0xab,0xa2,0xb0,0xfb,0x8d,0xe8,0x62,0x42,
    0x8b,0x0c,0x6c,0xc4,0x91,0x29,0x11,0x86,
    0x73,0xe0,0xcb,0x57,0xe9,0xef,0x68,0x53,
    0x26,0xd5,0xe4,0xb3,0x14,0x98,0x59,0x94,
    0x46,0xb1,0x65,0x3f,0xfa,0x47,0x26,0x96,
    0x4b,0x56,0x86,0x1e,0x2c,0x56,0x1f,0x71,
    0x84,0x34,0x3b,0xa3,0x53,0xc4,0x67,0x3d,
    0x92,0xa8,0x5c,0x6f,0xa5,0x20,0x1f,0xcb,
    0x60,0xbe,0x6d,0x4c,0x5f,0xc8,0xd6,0x0c,
    0x8a,0xb7,0x5f,0xb4,0x91,0x83,0xe8,0x1f,
    0xee,0x77,0xdf,0x86,0xfd,0x7a,0x3d,0x68,
    0xbd,0xee,0xa1,0xf2,0x10,0xb2,0xcf,0x8c,
    0x27,0x8d,0xe2,0x70,0x42,0x05,0x21,0x87,
    0x44,0xca,0xaa,0xa5,0x80,0x34,0x38,0x56,
    0x57,0x9b,0xbe,0x93,0xa2,0x23,0x52,0x81,
    0xbf,0x99,0x98,0xe9,0xfd,0x45,0x11,0x7d,
    0xc2,0x5f,0x2b,0x33,0xb8,0x9c,0xc3,0x6e,
    0xa2,0xa6,0x14,0x3c,0x0b,0x16,0xa5,0xa7,
    0x10,0x55,0xdd,0x8e,0x94,0x29,0x13,0x42,
    0x9b,0x20,0xfa,0xce,0xbf,0xde,0x81,0x10,
    0x2c,0xaa,0x23,0x24,0x10,0xef,0x52,0xc4,
    0xc2,0x3b,0x79,0xc9,0x29,0x28,0x62,0xad,
    0xf3,0xe2,0x81,0x0d,0xfa,0xe3,0x24,0xe6,
    0x53,0x34,0xca,0x74,0xf7,0xfe,0x56,0x98,
    0x93,0xaf,0x2e,0x91,0xaa,0x8c,0x51,0x27,
    0x88,0xf2,0xad,0x98,0x5e,0x5e,0x6b,0x7e,
    0xf5,0x93,0x2c,0x38,0x9b,0x7f,0x72,0xee,
    0x5a,0x75,0xdd,0x6f,0x97,0x56,0x43,0x7f,
    0xd0,0x0e,0xe6,0xb2,0x9b,0x3f,0x93,0xdc,
    0x48,0x98,0x19,0x05,0x91,0xab,0xf6,0x5a,
    0xc1,0x55,0x7e,0x71,0x01,0x9e,0x37,0xc5,
    0xdf,0xa8,0xf6,0xd6,0x03,0x78,0xc9,0x41,
    0xab,0x24,0x27,0xd9,0xc2,0xa7,0xa3,0x35,
    0x5d,0xd8,0x08,0xba,0x41,0xff,0x86,0x1b,
    0xdb,0xa0,0x30,0x8f,0x1f,0x79,0x32,0xd6,
    0x7f,0xd2,0xce,0x17,0x84,0xb6,0xb2,0xb7,
    0x77,0xe8,0x22,0x66,0x88,0xac,0x60,0x7c,
    0x11,0xf9,0x70,0x97,0xa9,0x0c,0xe5,0x02,
    0x39,0xd1,0xc4,0x3b,0x69,0xc2,0xcb,0xab,
    0xb0,0x08,0x36,0x24,0xf6,0x3e,0x48,0x48,
    0xe2,0x95,0xeb,0x49,0xe6,0xa4,0xd2,0x44,
    0x2b,0x84,0x9c,0xe5,0x39,0x84,0xa8,0x27,
    0x4b,0xce,0x38,0xd2,0x2f,0xf5,0x44,0xe0,
    0x2f,0x5d,0xa0,0xd0,0x3c,0x42,0xf3,0x59,
    0x10,0x03,0xf8,0xc1,0x53,0x62,0x04,0x35,
    0x0b,0x82,0x9e,0xc0,0x66,0x02,0x35,0x1e,
    0x95,0xd7,0x4a,0x20,0xd4,0x16,0xe7,0x66,
    0xa0,0x7d,0x7a,0x31,0xb7,0xc7,0x5c,0x12,
    0xca,0xbf,0x74,0xbe,0x61,0xfa,0xc0,0xae,
    0x21,0xd9,0x70,0x52,0xa6,0x1d,0x03,0x4a,
    0xd3,0x72,0xa5,0x8b,0x0a,0xd8,0xbf,0xeb,
    0x9c,0x24,0xf0,0x3a,0x3c,0xb4,0xe5,0x97,
    0x41,0xc4,0x2c,0x95,0x1b,0x6b,0xf3,0xc1,
    0xfe,0x4c,0x21,0x2b,0x09,0x59,0xb0,0x95,
    0xd6,0x27,0x94,0x56,0x0a,0x4d,0x75,0x4e,
    0xa8,0xb5,0x77,0x89,0xbc,0x79,0x1a,0x20,
    0xb2,0xd5,0xf8,0xb6,0x91,0x5f,0x3b,0x83,
    0x16,0x6e,0xb8,0xe6,0x64,0x00,0xa3,0xe2,
    0x8a,0xb6,0x79,0xc2,0x56,0x89,0x9f,0x82,
    0x10,0x16,0xe8,0x70,0x18,0x51,0xcd,0x00,
    0x95,0xaa,0x62,0x5d,0xcf,0x0a,0x4e,0xf0,
    0x28,0x03,0x5d,0x09,0x5c,0x6f,0x75,0xf7,
    0xdc,0x7f,0x60,0xf0,0x69,0x74,0xcb,0x57,
    0x09,0x1b,0x70,0x6e,0xf2,0x8d,0xa0,0x56,
    0x46,0xf4,0xeb,0xa1,0xc1,0xdf,0x4f,0xee,
    0x4e,0x0c,0x05,0x85,0xa2,0x02,0x4c,0x11,
    0x28,0x8c,0x7a,0xcd,0x19,0xe3,0x8b,0xd7,
    0x8d,0xd7,0x69,0x2b,0x9f,0xb8,0x26,0xe9,
    0x92,0x04,0x2e,0xfb,0xd7,0xfa,0xba,0x78,
    0x08,0x4d,0x18,0xd8,0x3f,0x81,0xac,0x86,
    0xbd,0x49,0x07,0xca,0x1a,0x45,0x74,0xae,
    0x94,0x56,0xf1,0x9d,0x6a,0x5a,0x88,0x45,
    0xe1,0x5b,0xf7,0xcf,0xef,0xe7,0xa9,0x2b,
    0x20,0xeb,0x8d,0x66,0x6c,0x4e,0x1a,0x18,
    0xe8,0x09,0xe6,0xd9,0xf7,0xfc,0x61,0x16,
    0x78,0xed,0x67,0xf8,0x4f,0xf7,0xaa,0xc9,
    0x87,0x52,0x2a,0xaf,0x76,0xa9,0x47,0xca,
    0x67,0x45,0x13,0x3c,0x5f,0xa1,0xe8,0x6b,
    0x18,0x3c,0x83,0xca,0x7a,0xef,0xf8,0x6e,
    0x85,0x4c,0x78,0xe3,0x6d,0x96,0x0b,0x3a,
    0x0a,0xd1,0x39,0x0d,0x47,0xb9,0x2d,0x3b,
    0x16,0xe0,0x8b,0x36,0xe7,0xed,0x35,0x16,
    0x0d,0xbf,0xbf,0x44,0xf1,0xbb,0xcc,0x58,
    0x34,0x05,0xfd,0xff,0xcf,0x0f,0x59,0xce,
    0xa5,0x99,0xb3,0x1a,0xdb,0xd5,0xec,0xcd,
    0xb7,0x4e,0x87,0x53,0x29,0x0c,0xd7,0xad,
    0xea,0x2d,0x17,0x16,0x03,0x1d,0xce,0xbe,
    0xcc,0x32,0xdb,0x55,0xc6,0xa4,0x7e,0x2c,
    0x92,0x6e,0xf3,0x84,0x8e,0x3d,0x8c,0x72,
    0xbe,0xb0,0x3c,0x90,0x96,0xd3,0x54,0x70,
    0xf9,0x61,0x0f,0xb4,0xe4,0xa0,0x29,0x3b,
    0x7f,0x99,0xaf,0x16,0x59,0x67,0xc9,0x0b,
    0xc7,0x37,0x20,0x32,0xc2,0xed,0xb1,0x33,
    0xa1,0x9f,0xa9,0x7c,0x05,0xb3,0x36,0x8c,
    0x3c,0x30,0x20,0x58,0xfc,0x05,0x97,0x06,
    0xd0,0xc3,0xe1,0x7a,0xb3,0x38,0xa5,0x3b,
    0x10,0x60,0x69,0x72,0x30,0x7e,0xf8,0x40,
    0x1d,0xa2,0x3a,0xd1,0x67,0x2b,0x4e,0x4d,
    0x59,0x6b,0xf4,0x57,0x28,0xed,0x12,0xeb,
    0x82,0x68,0xd4,0xf2,0x97,0xe7,0x84,0x16,
    0xba,0x39,0x4a,0xd3,0xaf,0xf0,0x37,0xdd,
    0x51,0x07,0x69,0xca,0xf4,0xbd,0x50,0x1b,
    0xe1,0x68,0xd1,0xfd,0xf1,0x45,0x7c,0xbc,
    0x7b,0x84,0xb6,0x93,0x29,0xc0,0xda,0x70,
    0xe6,0x0d,0xfc,0xdb,0xd8,0x5d,0x32,0xd6,
    0x50,0x0f,0x67,0xce,0x1b,0x99,0x47,0xb2,
    0x9c,0x6c,0xfa,0x75,0x79,0x43,0x03,0xea,
    0xb5,0xa7,0xc9,0xff,0x06,0x29,0x03,0x6a,
    0xa3,0xe7,0x45,0x85,0x7c,0xa5,0x76,0x9e,
    0x4f,0x09,0x3f,0x41,0xb7,0x7a,0xa6,0xfd,
    0xfb,0x83,0xe2,0x43,0x80,0x80,0x48,0x3f,
    0x7f,0x2b,0x79,0xd4,0x53,0x06,0x38,0xc9,
    0x91,0x52,0x17,0x85,0xe7,0x32,0x26,0xc8,
};
