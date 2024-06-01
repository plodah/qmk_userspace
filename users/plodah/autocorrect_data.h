// Copyright 2024 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

/*******************************************************************************
  88888888888 888      d8b                .d888 d8b 888               d8b
      888     888      Y8P               d88P"  Y8P 888               Y8P
      888     888                        888        888
      888     88888b.  888 .d8888b       888888 888 888  .d88b.       888 .d8888b
      888     888 "88b 888 88K           888    888 888 d8P  Y8b      888 88K
      888     888  888 888 "Y8888b.      888    888 888 88888888      888 "Y8888b.
      888     888  888 888      X88      888    888 888 Y8b.          888      X88
      888     888  888 888  88888P'      888    888 888  "Y8888       888  88888P'
                                                        888                 888
                                                        888                 888
                                                        888                 888
     .d88b.   .d88b.  88888b.   .d88b.  888d888 8888b.  888888 .d88b.   .d88888
    d88P"88b d8P  Y8b 888 "88b d8P  Y8b 888P"      "88b 888   d8P  Y8b d88" 888
    888  888 88888888 888  888 88888888 888    .d888888 888   88888888 888  888
    Y88b 888 Y8b.     888  888 Y8b.     888    888  888 Y88b. Y8b.     Y88b 888
     "Y88888  "Y8888  888  888  "Y8888  888    "Y888888  "Y888 "Y8888   "Y88888
         888
    Y8b d88P
     "Y88P"
*******************************************************************************/

#pragma once

// Autocorrection dictionary (67 entries):
//   fitler    -> filter
//   somehting -> something
//   :thier    -> their
//   abotu     -> about
//   profuct   -> product
//   verisons  -> versions
//   lenght    -> length
//   ouput     -> output
//   widht     -> width
//   :esle     -> else
//   :adn:     -> and
//   :agian    -> again
//   :andteh   -> and the
//   :andthe   -> and the
//   :aslo:    -> also
//   :asthe:   -> as the
//   :atthe    -> at the
//   :ergard   -> regard
//   :gt:      -> git
//   :haev     -> have
//   :hten:    -> then
//   :hte:     -> the
//   :htere    -> there
//   :hting    -> thing
//   :inot:    -> into
//   :iwll     -> will
//   :iwth     -> with
//   :lastr:   -> last
//   :leran    -> learn
//   :loev     -> love
//   :lsat     -> last
//   :lveo     -> love
//   :lvoe     -> love
//   :nad:     -> and
//   :nto:     -> not
//   :onyl:    -> only
//   :ocuntry  -> country
//   :ot:      -> to
//   :ous:     -> our
//   :oru:     -> our
//   :owrk     -> work
//   :smae:    -> same
//   :smoe:    -> some
//   :socre    -> score
//   :soem:    -> some
//   :sohw:    -> show
//   :sourth:  -> south
//   :stpo:    -> stop
//   :syas:    -> says
//   :szie     -> size
//   :tath:    -> that
//   :teh:     -> the
//   :tehy:    -> they
//   :thn:     -> then
//   :thna:    -> than
//   :thne:    -> then
//   :thsi:    -> this
//   :thta:    -> that
//   :tiem:    -> time
//   :tihs:    -> this
//   :tje:     -> the
//   :tjhe:    -> the
//   :tkae:    -> take
//   :tothe    -> to the
//   :ture     -> true
//   :turth    -> truth
//   :tust:    -> trust

#define AUTOCORRECT_MIN_LENGTH 4 // ":gt:"
#define AUTOCORRECT_MAX_LENGTH 9 // "somehting"
#define DICTIONARY_SIZE 912

static const uint8_t autocorrect_data[DICTIONARY_SIZE] PROGMEM = {
    0x6C, 0x2E, 0x00, 0x07, 0xE3, 0x01, 0x08, 0xF2, 0x01, 0x0A, 0x6C, 0x02, 0x0B, 0x8A, 0x02, 0x0E,
    0xB7, 0x02, 0x0F, 0xC2, 0x02, 0x11, 0xCD, 0x02, 0x12, 0xE8, 0x02, 0x15, 0xF2, 0x02, 0x16, 0x0E,
    0x03, 0x17, 0x1D, 0x03, 0x18, 0x5F, 0x03, 0x19, 0x68, 0x03, 0x1C, 0x7F, 0x03, 0x00, 0x44, 0x5C,
    0x00, 0x07, 0x73, 0x00, 0x08, 0x7C, 0x00, 0x0B, 0xDE, 0x00, 0x0C, 0x04, 0x01, 0x0F, 0x0D, 0x01,
    0x10, 0x16, 0x01, 0x11, 0x2D, 0x01, 0x12, 0x4F, 0x01, 0x15, 0x71, 0x01, 0x16, 0x79, 0x01, 0x17,
    0x9B, 0x01, 0x18, 0xC7, 0x01, 0x1A, 0xCF, 0x01, 0x1C, 0xD9, 0x01, 0x00, 0x51, 0x63, 0x00, 0x17,
    0x6B, 0x00, 0x00, 0x0B, 0x17, 0x2C, 0x00, 0x82, 0x61, 0x6E, 0x00, 0x0B, 0x17, 0x2C, 0x00, 0x82,
    0x61, 0x74, 0x00, 0x04, 0x11, 0x2C, 0x00, 0x83, 0x61, 0x6E, 0x64, 0x00, 0x44, 0x8F, 0x00, 0x0B,
    0xA6, 0x00, 0x0D, 0xBE, 0x00, 0x11, 0xC5, 0x00, 0x12, 0xCD, 0x00, 0x17, 0xD6, 0x00, 0x00, 0x4E,
    0x96, 0x00, 0x10, 0x9E, 0x00, 0x00, 0x17, 0x2C, 0x00, 0x83, 0x61, 0x6B, 0x65, 0x00, 0x16, 0x2C,
    0x00, 0x83, 0x61, 0x6D, 0x65, 0x00, 0x4D, 0xAD, 0x00, 0x17, 0xB4, 0x00, 0x00, 0x17, 0x2C, 0x00,
    0x83, 0x68, 0x65, 0x00, 0x16, 0x04, 0x2C, 0x00, 0x83, 0x20, 0x74, 0x68, 0x65, 0x00, 0x17, 0x2C,
    0x00, 0x82, 0x68, 0x65, 0x00, 0x0B, 0x17, 0x2C, 0x00, 0x82, 0x65, 0x6E, 0x00, 0x10, 0x16, 0x2C,
    0x00, 0x83, 0x6F, 0x6D, 0x65, 0x00, 0x0B, 0x2C, 0x00, 0x83, 0x74, 0x68, 0x65, 0x00, 0x48, 0xE5,
    0x00, 0x17, 0xEC, 0x00, 0x00, 0x17, 0x2C, 0x00, 0x82, 0x68, 0x65, 0x00, 0x44, 0xF3, 0x00, 0x15,
    0xFB, 0x00, 0x00, 0x17, 0x2C, 0x00, 0x83, 0x68, 0x61, 0x74, 0x00, 0x18, 0x12, 0x16, 0x2C, 0x00,
    0x83, 0x74, 0x68, 0x00, 0x16, 0x0B, 0x17, 0x2C, 0x00, 0x82, 0x69, 0x73, 0x00, 0x1C, 0x11, 0x12,
    0x2C, 0x00, 0x82, 0x6C, 0x79, 0x00, 0x08, 0x00, 0x4C, 0x1F, 0x01, 0x12, 0x26, 0x01, 0x00, 0x17,
    0x2C, 0x00, 0x82, 0x6D, 0x65, 0x00, 0x16, 0x2C, 0x00, 0x82, 0x6D, 0x65, 0x00, 0x47, 0x37, 0x01,
    0x08, 0x3E, 0x01, 0x0B, 0x48, 0x01, 0x00, 0x04, 0x2C, 0x00, 0x82, 0x6E, 0x64, 0x00, 0x17, 0x0B,
    0x2C, 0x00, 0x84, 0x74, 0x68, 0x65, 0x6E, 0x00, 0x17, 0x2C, 0x00, 0x81, 0x65, 0x6E, 0x00, 0x4F,
    0x59, 0x01, 0x13, 0x62, 0x01, 0x17, 0x6A, 0x01, 0x00, 0x16, 0x04, 0x2C, 0x00, 0x83, 0x6C, 0x73,
    0x6F, 0x00, 0x17, 0x16, 0x2C, 0x00, 0x82, 0x6F, 0x70, 0x00, 0x11, 0x2C, 0x00, 0x82, 0x6F, 0x74,
    0x00, 0x17, 0x16, 0x04, 0x0F, 0x2C, 0x00, 0x81, 0x00, 0x44, 0x83, 0x01, 0x0B, 0x8C, 0x01, 0x18,
    0x95, 0x01, 0x00, 0x1C, 0x16, 0x2C, 0x00, 0x83, 0x61, 0x79, 0x73, 0x00, 0x0C, 0x17, 0x2C, 0x00,
    0x83, 0x68, 0x69, 0x73, 0x00, 0x12, 0x2C, 0x00, 0x81, 0x72, 0x00, 0x4A, 0xA5, 0x01, 0x12, 0xAB,
    0x01, 0x16, 0xBD, 0x01, 0x00, 0x2C, 0x00, 0x81, 0x69, 0x74, 0x00, 0x6C, 0xB2, 0x01, 0x11, 0xB6,
    0x01, 0x00, 0x82, 0x74, 0x6F, 0x00, 0x0C, 0x2C, 0x00, 0x82, 0x74, 0x6F, 0x00, 0x18, 0x17, 0x2C,
    0x00, 0x83, 0x72, 0x75, 0x73, 0x74, 0x00, 0x15, 0x12, 0x2C, 0x00, 0x82, 0x75, 0x72, 0x00, 0x0B,
    0x12, 0x16, 0x2C, 0x00, 0x83, 0x68, 0x6F, 0x77, 0x00, 0x0B, 0x08, 0x17, 0x2C, 0x00, 0x83, 0x68,
    0x65, 0x79, 0x00, 0x15, 0x04, 0x0A, 0x15, 0x08, 0x2C, 0x00, 0x85, 0x72, 0x65, 0x67, 0x61, 0x72,
    0x64, 0x00, 0x4B, 0x02, 0x02, 0x0C, 0x2A, 0x02, 0x0F, 0x33, 0x02, 0x12, 0x3C, 0x02, 0x15, 0x45,
    0x02, 0x00, 0x17, 0x00, 0x47, 0x0E, 0x02, 0x12, 0x18, 0x02, 0x17, 0x21, 0x02, 0x00, 0x11, 0x04,
    0x2C, 0x00, 0x82, 0x20, 0x74, 0x68, 0x65, 0x00, 0x17, 0x2C, 0x00, 0x82, 0x20, 0x74, 0x68, 0x65,
    0x00, 0x04, 0x2C, 0x00, 0x82, 0x20, 0x74, 0x68, 0x65, 0x00, 0x1D, 0x16, 0x2C, 0x00, 0x82, 0x69,
    0x7A, 0x65, 0x00, 0x16, 0x08, 0x2C, 0x00, 0x82, 0x6C, 0x73, 0x65, 0x00, 0x19, 0x0F, 0x2C, 0x00,
    0x82, 0x6F, 0x76, 0x65, 0x00, 0x46, 0x4F, 0x02, 0x08, 0x59, 0x02, 0x18, 0x64, 0x02, 0x00, 0x12,
    0x16, 0x2C, 0x00, 0x83, 0x63, 0x6F, 0x72, 0x65, 0x00, 0x17, 0x0B, 0x2C, 0x00, 0x84, 0x74, 0x68,
    0x65, 0x72, 0x65, 0x00, 0x17, 0x2C, 0x00, 0x82, 0x72, 0x75, 0x65, 0x00, 0x11, 0x0C, 0x17, 0x0B,
    0x00, 0x6C, 0x78, 0x02, 0x08, 0x7F, 0x02, 0x00, 0x84, 0x74, 0x68, 0x69, 0x6E, 0x67, 0x00, 0x10,
    0x12, 0x16, 0x00, 0x84, 0x74, 0x68, 0x69, 0x6E, 0x67, 0x00, 0x48, 0x91, 0x02, 0x17, 0x9D, 0x02,
    0x00, 0x17, 0x07, 0x11, 0x04, 0x2C, 0x00, 0x82, 0x20, 0x74, 0x68, 0x65, 0x00, 0x55, 0xA4, 0x02,
    0x1A, 0xAE, 0x02, 0x00, 0x18, 0x17, 0x2C, 0x00, 0x83, 0x72, 0x75, 0x74, 0x68, 0x00, 0x0C, 0x2C,
    0x00, 0x83, 0x77, 0x69, 0x74, 0x68, 0x00, 0x15, 0x1A, 0x12, 0x2C, 0x00, 0x83, 0x77, 0x6F, 0x72,
    0x6B, 0x00, 0x0F, 0x1A, 0x0C, 0x2C, 0x00, 0x83, 0x77, 0x69, 0x6C, 0x6C, 0x00, 0x04, 0x00, 0x4C,
    0xD6, 0x02, 0x15, 0xDF, 0x02, 0x00, 0x0A, 0x04, 0x2C, 0x00, 0x82, 0x61, 0x69, 0x6E, 0x00, 0x08,
    0x0F, 0x2C, 0x00, 0x82, 0x61, 0x72, 0x6E, 0x00, 0x08, 0x19, 0x0F, 0x2C, 0x00, 0x82, 0x6F, 0x76,
    0x65, 0x00, 0x08, 0x00, 0x4C, 0xFB, 0x02, 0x0F, 0x04, 0x03, 0x00, 0x0B, 0x17, 0x2C, 0x00, 0x82,
    0x65, 0x69, 0x72, 0x00, 0x17, 0x0C, 0x09, 0x00, 0x83, 0x6C, 0x74, 0x65, 0x72, 0x00, 0x11, 0x12,
    0x16, 0x0C, 0x15, 0x08, 0x19, 0x00, 0x84, 0x73, 0x69, 0x6F, 0x6E, 0x73, 0x00, 0x44, 0x2A, 0x03,
    0x06, 0x33, 0x03, 0x0B, 0x3F, 0x03, 0x18, 0x55, 0x03, 0x00, 0x16, 0x0F, 0x2C, 0x00, 0x82, 0x61,
    0x73, 0x74, 0x00, 0x18, 0x09, 0x12, 0x15, 0x13, 0x00, 0x83, 0x64, 0x75, 0x63, 0x74, 0x00, 0x47,
    0x46, 0x03, 0x0A, 0x4D, 0x03, 0x00, 0x0C, 0x1A, 0x00, 0x81, 0x74, 0x68, 0x00, 0x11, 0x08, 0x0F,
    0x00, 0x81, 0x74, 0x68, 0x00, 0x13, 0x18, 0x12, 0x00, 0x82, 0x74, 0x70, 0x75, 0x74, 0x00, 0x17,
    0x12, 0x05, 0x04, 0x00, 0x81, 0x75, 0x74, 0x00, 0x08, 0x00, 0x44, 0x71, 0x03, 0x12, 0x78, 0x03,
    0x00, 0x0B, 0x2C, 0x00, 0x81, 0x76, 0x65, 0x00, 0x0F, 0x2C, 0x00, 0x81, 0x76, 0x65, 0x00, 0x15,
    0x17, 0x11, 0x18, 0x06, 0x12, 0x2C, 0x00, 0x86, 0x63, 0x6F, 0x75, 0x6E, 0x74, 0x72, 0x79, 0x00
};
