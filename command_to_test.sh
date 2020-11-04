#compile and run
export LD_LIBRARY_PATH=/usr/local/cuda-11.1/lib64:$LD_LIBRARY_PATH;export R_LIBS_SITE=/home/ubuntu/saige/lib/:$R_LIBS_SITE
 R CMD INSTALL SAIGE --library=./lib

# Run the command
NVBLAS_CONFIG_FILE=~/nvblas.conf LD_PRELOAD=libnvblas.so Rscript ~/saige/SAIGE/extdata/step1_fitNULLGLMM.R             --plinkFile=./input/nfam_100_nindep_0_step1_includeMoreRareVariants_poly         --phenoFile=./input/pheno_1000samples.txt_withdosages_withBothTraitTypes.txt         --phenoCol=y_binary         --covarColList=x1,x2         --sampleIDColinphenoFile=IID         --traitType=binary                --outputPrefix=./output/example_binary_includenonAutoforvarRatio         --nThreads=4 --LOCO=FALSE --minMAFforGRM=0.01

