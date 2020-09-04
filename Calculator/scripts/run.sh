#!/bin/bash

run_simulator=1
custom_sim_port=0
simulator_port=26186
custom_sim_url=0
simulatorUrl="localhost"

run_backend=0
custom_backend_port=0
backend_port=26185
custom_backend_url=0
backendUrl="localhost"

logging=0
logging_cats_set=0
logging_cats=""

for arg in "$@"
do
  if [ "$arg" = "--no_simulation" ]
  then
    run_simulator=0
  elif [ "$arg" = "--simulator_port" ]
  then
    custom_sim_port=1
  elif [ "$custom_sim_port" -eq 1 ]
  then
    simulator_port=$arg
    custom_sim_port=0
    echo "Simulator port set to:" "$arg"
  elif [ "$arg" = "--simulator_url" ]
  then
    custom_sim_url=1
  elif [ "$custom_sim_url" -eq 1 ]
  then
    simulatorUrl=$arg
    custom_sim_url=0
    echo "Simulator url set to:" "$arg"
  elif [ "$arg" = "--remote_backend" ]
  then
    run_backend=1
  elif [ "$arg" = "--backend_port" ]
  then
    custom_backend_port=1
  elif [ "$custom_sim_port" -eq 1 ]
  then
    backend_port=$arg
    custom_backend_port=0
    echo "Backend port set to:" "$arg"
  elif [ "$arg" = "--backend_url" ]
  then
    custom_backend_url=1
  elif [ "$custom_backend_url" -eq 1 ]
  then
    backendUrl=$arg
    custom_backend_url=0
    echo "Backend url set to:" "$arg"
  elif [ "$arg" = "--logging" ]
  then
    logging=1
  elif [ "$logging" -eq 1 ]
  then
    logging_cats=$arg
    logging=0
    logging_cats_set=1
    echo "Logging categories set to:" "$arg"
  else
    echo "usage: run.sh [--no_simulation] [--simulator_port <simulator port>] [--simulator_url <simulator url>] [--remote_backend] [--backend_port <backend port>] [--backend_url <backend url>] [--logging <comma separted logging category list>]"
    exit 1
  fi
done

application_args=("-c" "plugins")
simulator_args=("--simulatorPort" "$simulator_port" "--simulatorUrl" "$simulatorUrl")
backend_args=("-c" "plugins" "--backendPort" "$backend_port" "--backendUrl" "$backendUrl")

if [ "$run_simulator" -eq 1 ]; then
  application_args+=("--simulator" "--simulatorPort" "$simulator_port" "--simulatorUrl" "$simulatorUrl")
fi

if [ "$run_backend" -eq 1 ]; then
  application_args+=("--remoteBackend" "--backendPort" "$backend_port" "--backendUrl" "$backendUrl")
fi

if [ "$logging_cats_set" -eq 1 ]; then
  application_args+=("-d" "$logging_cats")
  simulator_args+=("-d" "$logging_cats")
  backend_args+=("-d" "$logging_cats")
fi

if [ -d "bin/Calculator.app" ]; then
#MacOS
  if [ "$run_simulator" -eq 1 ]; then
    DYLD_LIBRARY_PATH=lib bin/Calculator_Simulator.app/Contents/MacOS/Calculator_Simulator "${simulator_args[@]}" &
  fi
  if [ "$run_backend" -eq 1 ]; then
    DYLD_LIBRARY_PATH=lib bin/Calculator_Backend.app/Contents/MacOS/Calculator_Backend "${backend_args[@]}" &
  fi
  DYLD_LIBRARY_PATH=lib bin/Calculator.app/Contents/MacOS/Calculator "${application_args[@]}" &
else
#Linux
  if [ "$run_simulator" -eq 1 ]; then
    LD_LIBRARY_PATH=lib bin/Calculator_Simulator "${simulator_args[@]}" &
  fi
  if [ "$run_backend" -eq 1 ]; then
    LD_LIBRARY_PATH=lib bin/Calculator_Backend "${backend_args[@]}" &
  fi
  LD_LIBRARY_PATH=lib bin/Calculator "${application_args[@]}" &
fi
