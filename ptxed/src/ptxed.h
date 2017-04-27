#ifndef PTXED_H
#define PTXED_H

/* The type of decoder to be used. */
enum ptxed_decoder_type {
	pdt_insn_decoder,
	pdt_block_decoder
};

/* The decoder to use. */
struct ptxed_decoder {
	/* The decoder type. */
	enum ptxed_decoder_type type;

	/* The actual decoder. */
	union {
		/* If @type == pdt_insn_decoder */
		struct pt_insn_decoder *insn;

		/* If @type == pdt_block_decoder */
		struct pt_block_decoder *block;
	} variant;
};

/* A collection of options. */
struct ptxed_options {
	/* Do not print the instruction. */
	uint32_t dont_print_insn:1;

	/* Remain as quiet as possible - excluding error messages. */
	uint32_t quiet:1;

	/* Print statistics (overrides quiet). */
	uint32_t print_stats:1;

	/* Print information about section loads and unloads. */
	uint32_t track_image:1;

	/* Track blocks in the output.
	 *
	 * This only applies to the block decoder.
	 */
	uint32_t track_blocks:1;

	/* Print in AT&T format. */
	uint32_t att_format:1;

	/* Print the offset into the trace file. */
	uint32_t print_offset:1;

	/* Print the current timestamp. */
	uint32_t print_time:1;

	/* Print the raw bytes for an insn. */
	uint32_t print_raw_insn:1;

	/* Perform checks. */
	uint32_t check:1;
};

/* A collection of flags selecting which stats to collect/print. */
enum ptxed_stats_flag {
	/* Collect number of instructions. */
	ptxed_stat_insn		= (1 << 0),

	/* Collect number of blocks. */
	ptxed_stat_blocks	= (1 << 1)
};

/* A collection of statistics. */
struct ptxed_stats {
	/* The number of instructions. */
	uint64_t insn;

	/* The number of blocks.
	 *
	 * This only applies to the block decoder.
	 */
	uint64_t blocks;

	/* A collection of flags saying which statistics to collect/print. */
	uint32_t flags;
};

#endif
