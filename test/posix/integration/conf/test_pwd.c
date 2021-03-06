// This file is a part of the IncludeOS unikernel - www.includeos.org
//
// Copyright 2015-2017 Oslo and Akershus University College of Applied Sciences
// and Alfred Bratterud
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <pwd.h>
#include <stdio.h>

void print_pwd_entry(struct passwd* pwd_ent);

void test_pwd() {
  struct passwd* pwd_ent;

  while((pwd_ent = getpwent()) != NULL) {
    print_pwd_entry(pwd_ent);
  }

  printf("Back to start!\n");
  setpwent();
  pwd_ent = getpwent();
  print_pwd_entry(pwd_ent);
  endpwent();

  pwd_ent = getpwnam("root");
  if (pwd_ent != NULL) {
    print_pwd_entry(pwd_ent);
  }

  pwd_ent = getpwnam("alfred");
  if (pwd_ent != NULL) {
    print_pwd_entry(pwd_ent);
  }
}

void print_pwd_entry(struct passwd* pwd_ent) {
  printf("Name: %s\n", pwd_ent->pw_name);
  printf("Uid: %d\n", pwd_ent->pw_uid);
  printf("Gid: %d\n", pwd_ent->pw_gid);
  printf("Path: %s\n", pwd_ent->pw_dir);
  printf("Shell: %s\n\n", pwd_ent->pw_shell);
}
