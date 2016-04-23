# Copyright 2015 Adam Green (http://mbed.org/users/AdamGreen/)
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
PROJECT         := avionics
DEVICES         := LPC1768 LPC11U24 LPC4330_M4 KL25Z NRF51822
GCC4MBED_DIR    := /home/c1ockw0rk/gcc4mbed/
NO_FLOAT_SCANF  := 1
NO_FLOAT_PRINTF := 1

include $(GCC4MBED_DIR)/build/gcc4mbed.mk
