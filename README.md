# **M**ultiple **C**orrection in the **H**uman **G**enome

Depends:

- [Armadillo](http://arma.sourceforge.net/)
- [coRge](https://github.com/Chris1221/coRge)
- [plink1.9](https://www.cog-genomics.org/plink/1.9)
- [plink1.07](http://zzz.bwh.harvard.edu/plink/)
- [snptest](https://mathgen.stats.ox.ac.uk/genetics_software/snptest/snptest.html)

### Plans for development

The first priority is to understand how to take input arguements and parse them. We have a lot of parameters that need to be incorporated unfortuantely.

An example of intended usage:

```sh
./mchg --gen $GEN_FILE \ 
	--summary $SUMMARY_FILE \
	--output $OUTPUT_STREAM \
	--h2 $HERITABILITY \
	--pc $PERCENT_CAUSAL \
	--pnc $PERCENT_NON_CAUSAL \
	--nc $NUMBER_CAUSAL \
	--maf $MAF \
	--maf-range $MAF_RANGE \
	--nrep $NREP
```

Variables: 

- `$GEN_FILE`: File path to the `.gen` file. 
	- [File reference](https://www.cog-genomics.org/plink/1.9/input#oxford)
	- `std::string`
- `$SUMMARY_FILE`: File path to the `.summary` file.
	- Output of `snptest --summary-stats-only`, reference [here](https://mathgen.stats.ox.ac.uk/genetics_software/snptest/snptest.html#data_summaries)
	- `std::string`
- `$OUTPUT_STREAM`: File path to the output stream for depositing summary statistics.
	- `std::string`
- `$HERITABILITY`: 


Secondly 
