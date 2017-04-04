# **M**ultiple **C**orrection in the **H**uman **G**enome

Depends:

- [Armadillo](http://arma.sourceforge.net/)
- [coRge](https://github.com/Chris1221/coRge)
- [plink1.9](https://www.cog-genomics.org/plink/1.9)
- [plink1.07](http://zzz.bwh.harvard.edu/plink/)
- [snptest](https://mathgen.stats.ox.ac.uk/genetics_software/snptest/snptest.html)

### Explaination of Logic

The goal of this program is to take a genome (simulated using `HapGen2` off of a 1KG reference genome), superimpose an imaginary genetic condition, blind ourselves to the basis of this condition and attempt to identify the contributing variants through association analysis.  We can then use different multiple comparrisons techniques and attempt to identify 

1. Methods which identify more true positives while maintaining FDR or FWER
2. Contributing covariates to the disovery of variants

Full details of the implimentation may be found in the associated preprint -- please contact the maintainors for a current version. 

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
- `$HERITABILITY`: The heritability of the simulated condition.
	- `double` in [0,1]
- `$PERCENT_CAUSAL`: Percent of the causal variants to be included in the second strata. 
	- `double` in [0,1] 
- `$PERCENT_NON_CAUSAL`: Percent of the non-causal variants to be included in the second strata.
	- `double` in [0,1]
	- I know these two are confusing, but couldn't think of a better way to do this.
- `$NUMBER_CAUSAL`: Number of causal SNPs to be simulated
	- `int`
- `$MAF`: Simulate based on MAF bins or not
	- `bool`
- `$MAF_RANGE`: Vector of length two; lower end of the MAF and upper end of the MAF bin to be generated. 
	- `arma::vec`
- `$NREP`: Number of permutations to  perform
	- `int`



Secondly 
