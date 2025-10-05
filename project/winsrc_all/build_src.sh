build_pysrc()
{
    src_dir=$1
    dst_dir=$2
    module_name=$3
    module_ver=$(python -c "import sys, os; sys.path.append(r'$src_dir'); from $module_name import __version__ as v; print(v)")
    module_ver=$(echo $module_ver | sed -E 's/\./_/g')
    echo build ${module_name}_v${module_ver}.py
    cp -f $src_dir/${module_name}.py $dst_dir/${module_name}_v${module_ver}.py
}

build_csrc()
{
    src_dir=$1
    dst_dir=$2
    module_name=$3
    module_ver=$(awk '/.*_VERSION/ {print $3}' $src_dir/$module_name.h | sed 's/"//g')
    module_ver=$(echo $module_ver | sed -E 's/\./_/g')
    echo build ${module_name}_v${module_ver}.h
    cp -f $src_dir/${module_name}.h $dst_dir/${module_name}_v${module_ver}.h
}

mkdir -p $(dirname $0)/build
build_pysrc src $(dirname $0)/build windllin
build_csrc src $(dirname $0)/build commdef
build_csrc src $(dirname $0)/build winhook
build_csrc src $(dirname $0)/build windyn
build_csrc src $(dirname $0)/build winpe