/*
 * Copyright (c) 2020 Xilinx, Inc.
 * All rights reserved.
 *
 * This source code is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * The full GNU General Public License is included in this distribution in
 * the file called "COPYING".
 */
#ifndef __QDMA_ERROR_INFO__
#define __QDMA_ERROR_INFO__

#define NUM_LEAF_ERROR_AGGREGATORS 7

static u32 leaf_error_aggregators[NUM_LEAF_ERROR_AGGREGATORS] = {
	QDMA_DSC_ERR_ALL,
	QDMA_TRQ_ERR_ALL,
	QDMA_ST_C2H_ERR_ALL,
	QDMA_ST_FATAL_ERR_ALL,
	QDMA_ST_H2C_ERR_ALL,
	QDMA_SBE_ERR_ALL,
	QDMA_DBE_ERR_ALL
};

struct qdma_error_info {
	enum qdma_error_index idx;
	const char *name;
	u32 mask_reg_addr;
	u32 stat_reg_addr;
	u32 leaf_err_mask;
	u32 glbl_err_mask;
};

static struct qdma_error_info qdma_error_info[QDMA_ERR_ALL] = {
	/* Descriptor errors */
	{
		QDMA_DSC_ERR_POISON,
		"Poison error",
		QDMA_OFFSET_GLBL_DSC_ERR_MASK,
		QDMA_OFFSET_GLBL_DSC_ERR_STAT,
		QDMA_GLBL_DSC_ERR_POISON_MASK,
		QDMA_GLBL_ERR_DSC_MASK
	},
	{
		QDMA_DSC_ERR_UR_CA,
		"Unsupported request or completer aborted error",
		QDMA_OFFSET_GLBL_DSC_ERR_MASK,
		QDMA_OFFSET_GLBL_DSC_ERR_STAT,
		QDMA_GLBL_DSC_ERR_UR_CA_MASK,
		QDMA_GLBL_ERR_DSC_MASK
	},
	{
		QDMA_DSC_ERR_PARAM,
		"Parameter mismatch error",
		QDMA_OFFSET_GLBL_DSC_ERR_MASK,
		QDMA_OFFSET_GLBL_DSC_ERR_STAT,
		QDMA_GLBL_DSC_ERR_PARAM_MASK,
		QDMA_GLBL_ERR_DSC_MASK
	},
	{
		QDMA_DSC_ERR_ADDR,
		"Address mismatch error",
		QDMA_OFFSET_GLBL_DSC_ERR_MASK,
		QDMA_OFFSET_GLBL_DSC_ERR_STAT,
		QDMA_GLBL_DSC_ERR_ADDR_MASK,
		QDMA_GLBL_ERR_DSC_MASK
	},
	{
		QDMA_DSC_ERR_TAG,
		"Unexpected tag error",
		QDMA_OFFSET_GLBL_DSC_ERR_MASK,
		QDMA_OFFSET_GLBL_DSC_ERR_STAT,
		QDMA_GLBL_DSC_ERR_TAG_MASK,
		QDMA_GLBL_ERR_DSC_MASK
	},
	{
		QDMA_DSC_ERR_FLR,
		"FLR error",
		QDMA_OFFSET_GLBL_DSC_ERR_MASK,
		QDMA_OFFSET_GLBL_DSC_ERR_STAT,
		QDMA_GLBL_DSC_ERR_FLR_MASK,
		QDMA_GLBL_ERR_DSC_MASK
	},
	{
		QDMA_DSC_ERR_TIMEOUT,
		"Timed out error",
		QDMA_OFFSET_GLBL_DSC_ERR_MASK,
		QDMA_OFFSET_GLBL_DSC_ERR_STAT,
		QDMA_GLBL_DSC_ERR_TIMEOUT_MASK,
		QDMA_GLBL_ERR_DSC_MASK
	},
	{
		QDMA_DSC_ERR_DAT_POISON,
		"Poison data error",
		QDMA_OFFSET_GLBL_DSC_ERR_MASK,
		QDMA_OFFSET_GLBL_DSC_ERR_STAT,
		QDMA_GLBL_DSC_ERR_DAT_POISON_MASK,
		QDMA_GLBL_ERR_DSC_MASK
	},
	{
		QDMA_DSC_ERR_FLR_CANCEL,
		"Descriptor fetch cancelled due to FLR error",
		QDMA_OFFSET_GLBL_DSC_ERR_MASK,
		QDMA_OFFSET_GLBL_DSC_ERR_STAT,
		QDMA_GLBL_DSC_ERR_FLR_CANCEL_MASK,
		QDMA_GLBL_ERR_DSC_MASK
	},
	{
		QDMA_DSC_ERR_DMA,
		"DMA engine error",
		QDMA_OFFSET_GLBL_DSC_ERR_MASK,
		QDMA_OFFSET_GLBL_DSC_ERR_STAT,
		QDMA_GLBL_DSC_ERR_DMA_MASK,
		QDMA_GLBL_ERR_DSC_MASK
	},
	{
		QDMA_DSC_ERR_DSC,
		"Invalid PIDX update error",
		QDMA_OFFSET_GLBL_DSC_ERR_MASK,
		QDMA_OFFSET_GLBL_DSC_ERR_STAT,
		QDMA_GLBL_DSC_ERR_DSC_MASK,
		QDMA_GLBL_ERR_DSC_MASK
	},
	{
		QDMA_DSC_ERR_RQ_CANCEL,
		"Descriptor fetch cancelled due to disable register status error",
		QDMA_OFFSET_GLBL_DSC_ERR_MASK,
		QDMA_OFFSET_GLBL_DSC_ERR_STAT,
		QDMA_GLBL_DSC_ERR_RQ_CANCEL_MASK,
		QDMA_GLBL_ERR_DSC_MASK
	},
	{
		QDMA_DSC_ERR_DBE,
		"UNC_ERR_RAM_DBE error",
		QDMA_OFFSET_GLBL_DSC_ERR_MASK,
		QDMA_OFFSET_GLBL_DSC_ERR_STAT,
		QDMA_GLBL_DSC_ERR_DBE_MASK,
		QDMA_GLBL_ERR_DSC_MASK
	},
	{
		QDMA_DSC_ERR_SBE,
		"UNC_ERR_RAM_SBE error",
		QDMA_OFFSET_GLBL_DSC_ERR_MASK,
		QDMA_OFFSET_GLBL_DSC_ERR_STAT,
		QDMA_GLBL_DSC_ERR_SBE_MASK,
		QDMA_GLBL_ERR_DSC_MASK
	},
	{
		QDMA_DSC_ERR_ALL,
		"All Descriptor errors",
		QDMA_OFFSET_GLBL_DSC_ERR_MASK,
		QDMA_OFFSET_GLBL_DSC_ERR_STAT,
		QDMA_GLBL_DSC_ERR_ALL_MASK,
		QDMA_GLBL_ERR_DSC_MASK
	},

	/* TRQ errors */
	{
		QDMA_TRQ_ERR_UNMAPPED,
		"Access targeted unmapped register space error",
		QDMA_OFFSET_GLBL_TRQ_ERR_MASK,
		QDMA_OFFSET_GLBL_TRQ_ERR_STAT,
		QDMA_GLBL_TRQ_ERR_UNMAPPED_MASK,
		QDMA_GLBL_ERR_TRQ_MASK
	},
	{
		QDMA_TRQ_ERR_QID_RANGE,
		"Qid range error",
		QDMA_OFFSET_GLBL_TRQ_ERR_MASK,
		QDMA_OFFSET_GLBL_TRQ_ERR_STAT,
		QDMA_GLBL_TRQ_ERR_QID_RANGE_MASK,
		QDMA_GLBL_ERR_TRQ_MASK
	},
	{
		QDMA_TRQ_ERR_VF_ACCESS,
		"Invalid VF access error",
		QDMA_OFFSET_GLBL_TRQ_ERR_MASK,
		QDMA_OFFSET_GLBL_TRQ_ERR_STAT,
		QDMA_GLBL_TRQ_ERR_VF_ACCESS_MASK,
		QDMA_GLBL_ERR_TRQ_MASK
	},
	{
		QDMA_TRQ_ERR_TCP_TIMEOUT,
		"Timeout on request error",
		QDMA_OFFSET_GLBL_TRQ_ERR_MASK,
		QDMA_OFFSET_GLBL_TRQ_ERR_STAT,
		QDMA_GLBL_TRQ_ERR_TCP_TIMEOUT_MASK,
		QDMA_GLBL_ERR_TRQ_MASK
	},
	{
		QDMA_TRQ_ERR_ALL,
		"All TRQ errors",
		QDMA_OFFSET_GLBL_TRQ_ERR_MASK,
		QDMA_OFFSET_GLBL_TRQ_ERR_STAT,
		QDMA_GLBL_TRQ_ERR_ALL_MASK,
		QDMA_GLBL_ERR_TRQ_MASK
	},

	/* C2H Errors*/
	{
		QDMA_ST_C2H_ERR_MTY_MISMATCH,
		"MTY mismatch error",
		QDMA_OFFSET_C2H_ERR_MASK,
		QDMA_OFFSET_C2H_ERR_STAT,
		QDMA_C2H_ERR_MTY_MISMATCH_MASK,
		QDMA_GLBL_ERR_ST_C2H_MASK
	},
	{
		QDMA_ST_C2H_ERR_LEN_MISMATCH,
		"Packet length mismatch error",
		QDMA_OFFSET_C2H_ERR_MASK,
		QDMA_OFFSET_C2H_ERR_STAT,
		QDMA_C2H_ERR_LEN_MISMATCH_MASK,
		QDMA_GLBL_ERR_ST_C2H_MASK
	},
	{
		QDMA_ST_C2H_ERR_QID_MISMATCH,
		"Qid mismatch error",
		QDMA_OFFSET_C2H_ERR_MASK,
		QDMA_OFFSET_C2H_ERR_STAT,
		QDMA_C2H_ERR_QID_MISMATCH_MASK,
		QDMA_GLBL_ERR_ST_C2H_MASK
	},
	{
		QDMA_ST_C2H_ERR_DESC_RSP_ERR,
		"Descriptor error bit set",
		QDMA_OFFSET_C2H_ERR_MASK,
		QDMA_OFFSET_C2H_ERR_STAT,
		QDMA_C2H_ERR_DESC_RSP_ERR_MASK,
		QDMA_GLBL_ERR_ST_C2H_MASK
	},
	{
		QDMA_ST_C2H_ERR_ENG_WPL_DATA_PAR_ERR,
		"Data parity error",
		QDMA_OFFSET_C2H_ERR_MASK,
		QDMA_OFFSET_C2H_ERR_STAT,
		QDMA_C2H_ERR_ENG_WPL_DATA_PAR_ERR_MASK,
		QDMA_GLBL_ERR_ST_C2H_MASK
	},
	{
		QDMA_ST_C2H_ERR_MSI_INT_FAIL,
		"MSI got a fail response error",
		QDMA_OFFSET_C2H_ERR_MASK,
		QDMA_OFFSET_C2H_ERR_STAT,
		QDMA_C2H_ERR_MSI_INT_FAIL_MASK,
		QDMA_GLBL_ERR_ST_C2H_MASK
	},
	{
		QDMA_ST_C2H_ERR_ERR_DESC_CNT,
		"Descriptor count error",
		QDMA_OFFSET_C2H_ERR_MASK,
		QDMA_OFFSET_C2H_ERR_STAT,
		QDMA_C2H_ERR_ERR_DESC_CNT_MASK,
		QDMA_GLBL_ERR_ST_C2H_MASK
	},
	{
		QDMA_ST_C2H_ERR_PORTID_CTXT_MISMATCH,
		"Port id in packet and pfetch ctxt mismatch error",
		QDMA_OFFSET_C2H_ERR_MASK,
		QDMA_OFFSET_C2H_ERR_STAT,
		QDMA_C2H_ERR_PORTID_CTXT_MISMATCH_MASK,
		QDMA_GLBL_ERR_ST_C2H_MASK
	},
	{
		QDMA_ST_C2H_ERR_PORTID_BYP_IN_MISMATCH,
		"Port id in packet and bypass interface mismatch error",
		QDMA_OFFSET_C2H_ERR_MASK,
		QDMA_OFFSET_C2H_ERR_STAT,
		QDMA_C2H_ERR_PORTID_BYP_IN_MISMATCH_MASK,
		QDMA_GLBL_ERR_ST_C2H_MASK
	},
	{
		QDMA_ST_C2H_ERR_CMPL_INV_Q_ERR,
		"Writeback on invalid queue error",
		QDMA_OFFSET_C2H_ERR_MASK,
		QDMA_OFFSET_C2H_ERR_STAT,
		QDMA_C2H_ERR_CMPL_INV_Q_ERR_MASK,
		QDMA_GLBL_ERR_ST_C2H_MASK
	},
	{
		QDMA_ST_C2H_ERR_CMPL_QFULL_ERR,
		"Completion queue gets full error",
		QDMA_OFFSET_C2H_ERR_MASK,
		QDMA_OFFSET_C2H_ERR_STAT,
		QDMA_C2H_ERR_CMPL_QFULL_ERR_MASK,
		QDMA_GLBL_ERR_ST_C2H_MASK
	},
	{
		QDMA_ST_C2H_ERR_CMPL_CIDX_ERR,
		"Bad CIDX update by the software error",
		QDMA_OFFSET_C2H_ERR_MASK,
		QDMA_OFFSET_C2H_ERR_STAT,
		QDMA_C2H_ERR_CMPL_CIDX_ERR_MASK,
		QDMA_GLBL_ERR_ST_C2H_MASK
	},
	{
		QDMA_ST_C2H_ERR_CMPL_PRTY_ERR,
		"C2H completion Parity error",
		QDMA_OFFSET_C2H_ERR_MASK,
		QDMA_OFFSET_C2H_ERR_STAT,
		QDMA_C2H_ERR_CMPL_PRTY_ERR_MASK,
		QDMA_GLBL_ERR_ST_C2H_MASK
	},
	{
		QDMA_ST_C2H_ERR_ALL,
		"All C2h errors",
		QDMA_OFFSET_C2H_ERR_MASK,
		QDMA_OFFSET_C2H_ERR_STAT,
		QDMA_C2H_ERR_ALL_MASK,
		QDMA_GLBL_ERR_ST_C2H_MASK
	},

	/* C2H fatal errors */
	{
		QDMA_ST_FATAL_ERR_MTY_MISMATCH,
		"Fatal MTY mismatch error",
		QDMA_OFFSET_C2H_FATAL_ERR_MASK,
		QDMA_OFFSET_C2H_FATAL_ERR_STAT,
		QDMA_C2H_FATAL_ERR_MTY_MISMATCH_MASK,
		QDMA_GLBL_ERR_ST_C2H_MASK
	},
	{
		QDMA_ST_FATAL_ERR_LEN_MISMATCH,
		"Fatal Len mismatch error",
		QDMA_OFFSET_C2H_FATAL_ERR_MASK,
		QDMA_OFFSET_C2H_FATAL_ERR_STAT,
		QDMA_C2H_FATAL_ERR_LEN_MISMATCH_MASK,
		QDMA_GLBL_ERR_ST_C2H_MASK
	},
	{
		QDMA_ST_FATAL_ERR_QID_MISMATCH,
		"Fatal Qid mismatch error",
		QDMA_OFFSET_C2H_FATAL_ERR_MASK,
		QDMA_OFFSET_C2H_FATAL_ERR_STAT,
		QDMA_C2H_FATAL_ERR_QID_MISMATCH_MASK,
		QDMA_GLBL_ERR_ST_C2H_MASK
	},
	{
		QDMA_ST_FATAL_ERR_TIMER_FIFO_RAM_RDBE,
		"RAM double bit fatal error",
		QDMA_OFFSET_C2H_FATAL_ERR_MASK,
		QDMA_OFFSET_C2H_FATAL_ERR_STAT,
		QDMA_C2H_FATAL_ERR_TIMER_FIFO_RAM_RDBE_MASK,
		QDMA_GLBL_ERR_ST_C2H_MASK
	},
	{
		QDMA_ST_FATAL_ERR_PFCH_II_RAM_RDBE,
		"RAM double bit fatal error",
		QDMA_OFFSET_C2H_FATAL_ERR_MASK,
		QDMA_OFFSET_C2H_FATAL_ERR_STAT,
		QDMA_C2H_FATAL_ERR_PFCH_II_RAM_RDBE_MASK,
		QDMA_GLBL_ERR_ST_C2H_MASK
	},
	{
		QDMA_ST_FATAL_ERR_CMPL_CTXT_RAM_RDBE,
		"RAM double bit fatal error",
		QDMA_OFFSET_C2H_FATAL_ERR_MASK,
		QDMA_OFFSET_C2H_FATAL_ERR_STAT,
		QDMA_C2H_FATAL_ERR_CMPL_CTXT_RAM_RDBE_MASK,
		QDMA_GLBL_ERR_ST_C2H_MASK
	},
	{
		QDMA_ST_FATAL_ERR_PFCH_CTXT_RAM_RDBE,
		"RAM double bit fatal error",
		QDMA_OFFSET_C2H_FATAL_ERR_MASK,
		QDMA_OFFSET_C2H_FATAL_ERR_STAT,
		QDMA_C2H_FATAL_ERR_PFCH_CTXT_RAM_RDBE_MASK,
		QDMA_GLBL_ERR_ST_C2H_MASK
	},
	{
		QDMA_ST_FATAL_ERR_DESC_REQ_FIFO_RAM_RDBE,
		"RAM double bit fatal error",
		QDMA_OFFSET_C2H_FATAL_ERR_MASK,
		QDMA_OFFSET_C2H_FATAL_ERR_STAT,
		QDMA_C2H_FATAL_ERR_DESC_REQ_FIFO_RAM_RDBE_MASK,
		QDMA_GLBL_ERR_ST_C2H_MASK
	},
	{
		QDMA_ST_FATAL_ERR_INT_CTXT_RAM_RDBE,
		"RAM double bit fatal error",
		QDMA_OFFSET_C2H_FATAL_ERR_MASK,
		QDMA_OFFSET_C2H_FATAL_ERR_STAT,
		QDMA_C2H_FATAL_ERR_INT_CTXT_RAM_RDBE_MASK,
		QDMA_GLBL_ERR_ST_C2H_MASK
	},
	{
		QDMA_ST_FATAL_ERR_CMPL_COAL_DATA_RAM_RDBE,
		"RAM double bit fatal error",
		QDMA_OFFSET_C2H_FATAL_ERR_MASK,
		QDMA_OFFSET_C2H_FATAL_ERR_STAT,
		QDMA_C2H_FATAL_ERR_CMPL_COAL_DATA_RAM_RDBE_MASK,
		QDMA_GLBL_ERR_ST_C2H_MASK
	},
	{
		QDMA_ST_FATAL_ERR_TUSER_FIFO_RAM_RDBE,
		"RAM double bit fatal error",
		QDMA_OFFSET_C2H_FATAL_ERR_MASK,
		QDMA_OFFSET_C2H_FATAL_ERR_STAT,
		QDMA_C2H_FATAL_ERR_TUSER_FIFO_RAM_RDBE_MASK,
		QDMA_GLBL_ERR_ST_C2H_MASK
	},
	{
		QDMA_ST_FATAL_ERR_QID_FIFO_RAM_RDBE,
		"RAM double bit fatal error",
		QDMA_OFFSET_C2H_FATAL_ERR_MASK,
		QDMA_OFFSET_C2H_FATAL_ERR_STAT,
		QDMA_C2H_FATAL_ERR_QID_FIFO_RAM_RDBE_MASK,
		QDMA_GLBL_ERR_ST_C2H_MASK
	},
	{
		QDMA_ST_FATAL_ERR_PAYLOAD_FIFO_RAM_RDBE,
		"RAM double bit fatal error",
		QDMA_OFFSET_C2H_FATAL_ERR_MASK,
		QDMA_OFFSET_C2H_FATAL_ERR_STAT,
		QDMA_C2H_FATAL_ERR_PAYLOAD_FIFO_RAM_RDBE_MASK,
		QDMA_GLBL_ERR_ST_C2H_MASK
	},
	{
		QDMA_ST_FATAL_ERR_WPL_DATA_PAR,
		"RAM double bit fatal error",
		QDMA_OFFSET_C2H_FATAL_ERR_MASK,
		QDMA_OFFSET_C2H_FATAL_ERR_STAT,
		QDMA_C2H_FATAL_ERR_WPL_DATA_PAR_MASK,
		QDMA_GLBL_ERR_ST_C2H_MASK
	},
	{
		QDMA_ST_FATAL_ERR_ALL,
		"All fatal errors",
		QDMA_OFFSET_C2H_FATAL_ERR_MASK,
		QDMA_OFFSET_C2H_FATAL_ERR_STAT,
		QDMA_C2H_FATAL_ERR_ALL_MASK,
		QDMA_GLBL_ERR_ST_C2H_MASK
	},

	/* H2C St errors */
	{
		QDMA_ST_H2C_ERR_ZERO_LEN_DESC,
		"Zero length descriptor error",
		QDMA_OFFSET_H2C_ERR_MASK,
		QDMA_OFFSET_H2C_ERR_STAT,
		QDMA_H2C_ERR_ZERO_LEN_DESC_MASK,
		QDMA_GLBL_ERR_ST_H2C_MASK
	},
	{
		QDMA_ST_H2C_ERR_CSI_MOP,
		"Non EOP descriptor received error",
		QDMA_OFFSET_H2C_ERR_MASK,
		QDMA_OFFSET_H2C_ERR_STAT,
		QDMA_H2C_ERR_CSI_MOP_MASK,
		QDMA_GLBL_ERR_ST_H2C_MASK
	},
	{
		QDMA_ST_H2C_ERR_NO_DMA_DSC,
		"No DMA descriptor received error",
		QDMA_OFFSET_H2C_ERR_MASK,
		QDMA_OFFSET_H2C_ERR_STAT,
		QDMA_H2C_ERR_NO_DMA_DSC_MASK,
		QDMA_GLBL_ERR_ST_H2C_MASK
	},
	{
		QDMA_ST_H2C_ERR_SBE,
		"Single bit error detected on H2C-ST data error",
		QDMA_OFFSET_H2C_ERR_MASK,
		QDMA_OFFSET_H2C_ERR_STAT,
		QDMA_H2C_ERR_SBE_MASK,
		QDMA_GLBL_ERR_ST_H2C_MASK
	},
	{
		QDMA_ST_H2C_ERR_DBE,
		"Double bit error detected on H2C-ST data error",
		QDMA_OFFSET_H2C_ERR_MASK,
		QDMA_OFFSET_H2C_ERR_STAT,
		QDMA_H2C_ERR_DBE_MASK,
		QDMA_GLBL_ERR_ST_H2C_MASK
	},
	{
		QDMA_ST_H2C_ERR_ALL,
		"All H2C errors",
		QDMA_OFFSET_H2C_ERR_MASK,
		QDMA_OFFSET_H2C_ERR_STAT,
		QDMA_H2C_ERR_ALL_MASK,
		QDMA_GLBL_ERR_ST_H2C_MASK
	},

	/* SBE errors */
	{
		QDMA_SBE_ERR_MI_H2C0_DAT,
		"H2C MM data buffer single bit ECC error",
		QDMA_OFFSET_RAM_SBE_MASK,
		QDMA_OFFSET_RAM_SBE_STAT,
		QDMA_SBE_ERR_MI_H2C0_DAT_MASK,
		QDMA_GLBL_ERR_RAM_SBE_MASK
	},
	{
		QDMA_SBE_ERR_MI_C2H0_DAT,
		"C2H MM data buffer single bit ECC error",
		QDMA_OFFSET_RAM_SBE_MASK,
		QDMA_OFFSET_RAM_SBE_STAT,
		QDMA_SBE_ERR_MI_C2H0_DAT_MASK,
		QDMA_GLBL_ERR_RAM_SBE_MASK
	},
	{
		QDMA_SBE_ERR_H2C_RD_BRG_DAT,
		"Bridge master read single bit ECC error",
		QDMA_OFFSET_RAM_SBE_MASK,
		QDMA_OFFSET_RAM_SBE_STAT,
		QDMA_SBE_ERR_H2C_RD_BRG_DAT_MASK,
		QDMA_GLBL_ERR_RAM_SBE_MASK
	},
	{
		QDMA_SBE_ERR_H2C_WR_BRG_DAT,
		"Bridge master write single bit ECC error",
		QDMA_OFFSET_RAM_SBE_MASK,
		QDMA_OFFSET_RAM_SBE_STAT,
		QDMA_SBE_ERR_H2C_WR_BRG_DAT_MASK,
		QDMA_GLBL_ERR_RAM_SBE_MASK
	},
	{
		QDMA_SBE_ERR_C2H_RD_BRG_DAT,
		"Bridge slave read data buffer single bit ECC error",
		QDMA_OFFSET_RAM_SBE_MASK,
		QDMA_OFFSET_RAM_SBE_STAT,
		QDMA_SBE_ERR_C2H_RD_BRG_DAT_MASK,
		QDMA_GLBL_ERR_RAM_SBE_MASK
	},
	{
		QDMA_SBE_ERR_C2H_WR_BRG_DAT,
		"Bridge slave write data buffer single bit ECC error",
		QDMA_OFFSET_RAM_SBE_MASK,
		QDMA_OFFSET_RAM_SBE_STAT,
		QDMA_SBE_ERR_C2H_WR_BRG_DAT_MASK,
		QDMA_GLBL_ERR_RAM_SBE_MASK
	},
	{
		QDMA_SBE_ERR_FUNC_MAP,
		"Function map RAM single bit ECC error",
		QDMA_OFFSET_RAM_SBE_MASK,
		QDMA_OFFSET_RAM_SBE_STAT,
		QDMA_SBE_ERR_FUNC_MAP_MASK,
		QDMA_GLBL_ERR_RAM_SBE_MASK
	},
	{
		QDMA_SBE_ERR_DSC_HW_CTXT,
		"Descriptor engine hardware context RAM single bit ECC error",
		QDMA_OFFSET_RAM_SBE_MASK,
		QDMA_OFFSET_RAM_SBE_STAT,
		QDMA_SBE_ERR_DSC_HW_CTXT_MASK,
		QDMA_GLBL_ERR_RAM_SBE_MASK
	},
	{
		QDMA_SBE_ERR_DSC_CRD_RCV,
		"Descriptor engine receive credit context RAM single bit ECC error",
		QDMA_OFFSET_RAM_SBE_MASK,
		QDMA_OFFSET_RAM_SBE_STAT,
		QDMA_SBE_ERR_DSC_CRD_RCV_MASK,
		QDMA_GLBL_ERR_RAM_SBE_MASK
	},
	{
		QDMA_SBE_ERR_DSC_SW_CTXT,
		"Descriptor engine software context RAM single bit ECC error",
		QDMA_OFFSET_RAM_SBE_MASK,
		QDMA_OFFSET_RAM_SBE_STAT,
		QDMA_SBE_ERR_DSC_SW_CTXT_MASK,
		QDMA_GLBL_ERR_RAM_SBE_MASK
	},
	{
		QDMA_SBE_ERR_DSC_CPLI,
		"Descriptor engine fetch completion information RAM single bit ECC error",
		QDMA_OFFSET_RAM_SBE_MASK,
		QDMA_OFFSET_RAM_SBE_STAT,
		QDMA_SBE_ERR_DSC_CPLI_MASK,
		QDMA_GLBL_ERR_RAM_SBE_MASK
	},
	{
		QDMA_SBE_ERR_DSC_CPLD,
		"Descriptor engine fetch completion data RAM single bit ECC error",
		QDMA_OFFSET_RAM_SBE_MASK,
		QDMA_OFFSET_RAM_SBE_STAT,
		QDMA_SBE_ERR_DSC_CPLD_MASK,
		QDMA_GLBL_ERR_RAM_SBE_MASK
	},
	{
		QDMA_SBE_ERR_PASID_CTXT_RAM,
		"PASID configuration RAM single bit ECC error",
		QDMA_OFFSET_RAM_SBE_MASK,
		QDMA_OFFSET_RAM_SBE_STAT,
		QDMA_SBE_ERR_PASID_CTXT_RAM_MASK,
		QDMA_GLBL_ERR_RAM_SBE_MASK
	},
	{
		QDMA_SBE_ERR_TIMER_FIFO_RAM,
		"Timer fifo RAM single bit ECC error",
		QDMA_OFFSET_RAM_SBE_MASK,
		QDMA_OFFSET_RAM_SBE_STAT,
		QDMA_SBE_ERR_TIMER_FIFO_RAM_MASK,
		QDMA_GLBL_ERR_RAM_SBE_MASK
	},
	{
		QDMA_SBE_ERR_PAYLOAD_FIFO_RAM,
		"C2H ST payload RAM single bit ECC error",
		QDMA_OFFSET_RAM_SBE_MASK,
		QDMA_OFFSET_RAM_SBE_STAT,
		QDMA_SBE_ERR_PAYLOAD_FIFO_RAM_MASK,
		QDMA_GLBL_ERR_RAM_SBE_MASK
	},
	{
		QDMA_SBE_ERR_QID_FIFO_RAM,
		"C2H ST QID FIFO RAM single bit ECC error",
		QDMA_OFFSET_RAM_SBE_MASK,
		QDMA_OFFSET_RAM_SBE_STAT,
		QDMA_SBE_ERR_QID_FIFO_RAM_MASK,
		QDMA_GLBL_ERR_RAM_SBE_MASK
	},
	{
		QDMA_SBE_ERR_TUSER_FIFO_RAM,
		"C2H ST TUSER RAM single bit ECC error",
		QDMA_OFFSET_RAM_SBE_MASK,
		QDMA_OFFSET_RAM_SBE_STAT,
		QDMA_SBE_ERR_TUSER_FIFO_RAM_MASK,
		QDMA_GLBL_ERR_RAM_SBE_MASK
	},
	{
		QDMA_SBE_ERR_WB_COAL_DATA_RAM,
		"Completion Coalescing RAM single bit ECC error",
		QDMA_OFFSET_RAM_SBE_MASK,
		QDMA_OFFSET_RAM_SBE_STAT,
		QDMA_SBE_ERR_WB_COAL_DATA_RAM_MASK,
		QDMA_GLBL_ERR_RAM_SBE_MASK
	},
	{
		QDMA_SBE_ERR_INT_QID2VEC_RAM,
		"Interrupt QID2VEC RAM single bit ECC error",
		QDMA_OFFSET_RAM_SBE_MASK,
		QDMA_OFFSET_RAM_SBE_STAT,
		QDMA_SBE_ERR_INT_QID2VEC_RAM_MASK,
		QDMA_GLBL_ERR_RAM_SBE_MASK
	},
	{
		QDMA_SBE_ERR_INT_CTXT_RAM,
		"Interrupt context RAM single bit ECC error",
		QDMA_OFFSET_RAM_SBE_MASK,
		QDMA_OFFSET_RAM_SBE_STAT,
		QDMA_SBE_ERR_INT_CTXT_RAM_MASK,
		QDMA_GLBL_ERR_RAM_SBE_MASK
	},
	{
		QDMA_SBE_ERR_DESC_REQ_FIFO_RAM,
		"C2H ST descriptor request RAM single bit ECC error",
		QDMA_OFFSET_RAM_SBE_MASK,
		QDMA_OFFSET_RAM_SBE_STAT,
		QDMA_SBE_ERR_DESC_REQ_FIFO_RAM_MASK,
		QDMA_GLBL_ERR_RAM_SBE_MASK
	},
	{
		QDMA_SBE_ERR_PFCH_CTXT_RAM,
		"C2H ST prefetch RAM single bit ECC error",
		QDMA_OFFSET_RAM_SBE_MASK,
		QDMA_OFFSET_RAM_SBE_STAT,
		QDMA_SBE_ERR_PFCH_CTXT_RAM_MASK,
		QDMA_GLBL_ERR_RAM_SBE_MASK
	},
	{
		QDMA_SBE_ERR_WB_CTXT_RAM,
		"C2H ST completion context RAM single bit ECC error",
		QDMA_OFFSET_RAM_SBE_MASK,
		QDMA_OFFSET_RAM_SBE_STAT,
		QDMA_SBE_ERR_WB_CTXT_RAM_MASK,
		QDMA_GLBL_ERR_RAM_SBE_MASK
	},
	{
		QDMA_SBE_ERR_PFCH_LL_RAM,
		"C2H ST prefetch list RAM single bit ECC error",
		QDMA_OFFSET_RAM_SBE_MASK,
		QDMA_OFFSET_RAM_SBE_STAT,
		QDMA_SBE_ERR_PFCH_LL_RAM_MASK,
		QDMA_GLBL_ERR_RAM_SBE_MASK
	},
	{
		QDMA_SBE_ERR_H2C_PEND_FIFO,
		"H2C ST pending fifo RAM single bit ECC error",
		QDMA_OFFSET_RAM_SBE_MASK,
		QDMA_OFFSET_RAM_SBE_STAT,
		QDMA_SBE_ERR_H2C_PEND_FIFO_MASK,
		QDMA_GLBL_ERR_RAM_SBE_MASK
	},
	{
		QDMA_SBE_ERR_ALL,
		"All SBE errors",
		QDMA_OFFSET_RAM_SBE_MASK,
		QDMA_OFFSET_RAM_SBE_STAT,
		QDMA_SBE_ERR_ALL_MASK,
		QDMA_GLBL_ERR_RAM_SBE_MASK
	},


	/* DBE Errors */
	{
		QDMA_DBE_ERR_MI_H2C0_DAT,
		"H2C MM data buffer double bit ECC error",
		QDMA_OFFSET_RAM_DBE_MASK,
		QDMA_OFFSET_RAM_DBE_STAT,
		QDMA_DBE_ERR_MI_H2C0_DAT_MASK,
		QDMA_GLBL_ERR_RAM_DBE_MASK
	},
	{
		QDMA_DBE_ERR_MI_C2H0_DAT,
		"C2H MM data buffer double bit ECC error",
		QDMA_OFFSET_RAM_DBE_MASK,
		QDMA_OFFSET_RAM_DBE_STAT,
		QDMA_DBE_ERR_MI_C2H0_DAT_MASK,
		QDMA_GLBL_ERR_RAM_DBE_MASK
	},
	{
		QDMA_DBE_ERR_H2C_RD_BRG_DAT,
		"Bridge master read double bit ECC error",
		QDMA_OFFSET_RAM_DBE_MASK,
		QDMA_OFFSET_RAM_DBE_STAT,
		QDMA_DBE_ERR_H2C_RD_BRG_DAT_MASK,
		QDMA_GLBL_ERR_RAM_DBE_MASK
	},
	{
		QDMA_DBE_ERR_H2C_WR_BRG_DAT,
		"Bridge master write double bit ECC error",
		QDMA_OFFSET_RAM_DBE_MASK,
		QDMA_OFFSET_RAM_DBE_STAT,
		QDMA_DBE_ERR_H2C_WR_BRG_DAT_MASK,
		QDMA_GLBL_ERR_RAM_DBE_MASK
	},
	{
		QDMA_DBE_ERR_C2H_RD_BRG_DAT,
		"Bridge slave read data buffer double bit ECC error",
		QDMA_OFFSET_RAM_DBE_MASK,
		QDMA_OFFSET_RAM_DBE_STAT,
		QDMA_DBE_ERR_C2H_RD_BRG_DAT_MASK,
		QDMA_GLBL_ERR_RAM_DBE_MASK
	},
	{
		QDMA_DBE_ERR_C2H_WR_BRG_DAT,
		"Bridge slave write data buffer double bit ECC error",
		QDMA_OFFSET_RAM_DBE_MASK,
		QDMA_OFFSET_RAM_DBE_STAT,
		QDMA_DBE_ERR_C2H_WR_BRG_DAT_MASK,
		QDMA_GLBL_ERR_RAM_DBE_MASK
	},
	{
		QDMA_DBE_ERR_FUNC_MAP,
		"Function map RAM double bit ECC error",
		QDMA_OFFSET_RAM_DBE_MASK,
		QDMA_OFFSET_RAM_DBE_STAT,
		QDMA_DBE_ERR_FUNC_MAP_MASK,
		QDMA_GLBL_ERR_RAM_DBE_MASK
	},
	{
		QDMA_DBE_ERR_DSC_HW_CTXT,
		"Descriptor engine hardware context RAM double bit ECC error",
		QDMA_OFFSET_RAM_DBE_MASK,
		QDMA_OFFSET_RAM_DBE_STAT,
		QDMA_DBE_ERR_DSC_HW_CTXT_MASK,
		QDMA_GLBL_ERR_RAM_DBE_MASK
	},
	{
		QDMA_DBE_ERR_DSC_CRD_RCV,
		"Descriptor engine receive credit context RAM double bit ECC error",
		QDMA_OFFSET_RAM_DBE_MASK,
		QDMA_OFFSET_RAM_DBE_STAT,
		QDMA_DBE_ERR_DSC_CRD_RCV_MASK,
		QDMA_GLBL_ERR_RAM_DBE_MASK
	},
	{
		QDMA_DBE_ERR_DSC_SW_CTXT,
		"Descriptor engine software context RAM double bit ECC error",
		QDMA_OFFSET_RAM_DBE_MASK,
		QDMA_OFFSET_RAM_DBE_STAT,
		QDMA_DBE_ERR_DSC_SW_CTXT_MASK,
		QDMA_GLBL_ERR_RAM_DBE_MASK
	},
	{
		QDMA_DBE_ERR_DSC_CPLI,
		"Descriptor engine fetch completion information RAM double bit ECC error",
		QDMA_OFFSET_RAM_DBE_MASK,
		QDMA_OFFSET_RAM_DBE_STAT,
		QDMA_DBE_ERR_DSC_CPLI_MASK,
		QDMA_GLBL_ERR_RAM_DBE_MASK
	},
	{
		QDMA_DBE_ERR_DSC_CPLD,
		"Descriptor engine fetch completion data RAM double bit ECC error",
		QDMA_OFFSET_RAM_DBE_MASK,
		QDMA_OFFSET_RAM_DBE_STAT,
		QDMA_DBE_ERR_DSC_CPLD_MASK,
		QDMA_GLBL_ERR_RAM_DBE_MASK
	},
	{
		QDMA_DBE_ERR_PASID_CTXT_RAM,
		"PASID configuration RAM double bit ECC error",
		QDMA_OFFSET_RAM_DBE_MASK,
		QDMA_OFFSET_RAM_DBE_STAT,
		QDMA_DBE_ERR_PASID_CTXT_RAM_MASK,
		QDMA_GLBL_ERR_RAM_DBE_MASK
	},
	{
		QDMA_DBE_ERR_TIMER_FIFO_RAM,
		"Timer fifo RAM double bit ECC error",
		QDMA_OFFSET_RAM_DBE_MASK,
		QDMA_OFFSET_RAM_DBE_STAT,
		QDMA_DBE_ERR_TIMER_FIFO_RAM_MASK,
		QDMA_GLBL_ERR_RAM_DBE_MASK
	},
	{
		QDMA_DBE_ERR_PAYLOAD_FIFO_RAM,
		"C2H ST payload RAM double bit ECC error",
		QDMA_OFFSET_RAM_DBE_MASK,
		QDMA_OFFSET_RAM_DBE_STAT,
		QDMA_DBE_ERR_PAYLOAD_FIFO_RAM_MASK,
		QDMA_GLBL_ERR_RAM_DBE_MASK
	},
	{
		QDMA_DBE_ERR_QID_FIFO_RAM,
		"C2H ST QID FIFO RAM double bit ECC error",
		QDMA_OFFSET_RAM_DBE_MASK,
		QDMA_OFFSET_RAM_DBE_STAT,
		QDMA_DBE_ERR_QID_FIFO_RAM_MASK,
		QDMA_GLBL_ERR_RAM_DBE_MASK
	},
	{
		QDMA_DBE_ERR_TUSER_FIFO_RAM,
		"C2H ST TUSER RAM double bit ECC error",
		QDMA_OFFSET_RAM_DBE_MASK,
		QDMA_OFFSET_RAM_DBE_STAT,
		QDMA_DBE_ERR_TUSER_FIFO_RAM_MASK,
		QDMA_GLBL_ERR_RAM_DBE_MASK
	},
	{
		QDMA_DBE_ERR_WB_COAL_DATA_RAM,
		"Completion Coalescing RAM double bit ECC error",
		QDMA_OFFSET_RAM_DBE_MASK,
		QDMA_OFFSET_RAM_DBE_STAT,
		QDMA_DBE_ERR_WB_COAL_DATA_RAM_MASK,
		QDMA_GLBL_ERR_RAM_DBE_MASK
	},
	{
		QDMA_DBE_ERR_INT_QID2VEC_RAM,
		"Interrupt QID2VEC RAM double bit ECC error",
		QDMA_OFFSET_RAM_DBE_MASK,
		QDMA_OFFSET_RAM_DBE_STAT,
		QDMA_DBE_ERR_INT_QID2VEC_RAM_MASK,
		QDMA_GLBL_ERR_RAM_DBE_MASK
	},
	{
		QDMA_DBE_ERR_INT_CTXT_RAM,
		"Interrupt context RAM double bit ECC error",
		QDMA_OFFSET_RAM_DBE_MASK,
		QDMA_OFFSET_RAM_DBE_STAT,
		QDMA_DBE_ERR_INT_CTXT_RAM_MASK,
		QDMA_GLBL_ERR_RAM_DBE_MASK
	},
	{
		QDMA_DBE_ERR_DESC_REQ_FIFO_RAM,
		"C2H ST descriptor request RAM double bit ECC error",
		QDMA_OFFSET_RAM_DBE_MASK,
		QDMA_OFFSET_RAM_DBE_STAT,
		QDMA_DBE_ERR_DESC_REQ_FIFO_RAM_MASK,
		QDMA_GLBL_ERR_RAM_DBE_MASK
	},
	{
		QDMA_DBE_ERR_PFCH_CTXT_RAM,
		"C2H ST prefetch RAM double bit ECC error",
		QDMA_OFFSET_RAM_DBE_MASK,
		QDMA_OFFSET_RAM_DBE_STAT,
		QDMA_DBE_ERR_PFCH_CTXT_RAM_MASK,
		QDMA_GLBL_ERR_RAM_DBE_MASK
	},
	{
		QDMA_DBE_ERR_WB_CTXT_RAM,
		"C2H ST completion context RAM double bit ECC error",
		QDMA_OFFSET_RAM_DBE_MASK,
		QDMA_OFFSET_RAM_DBE_STAT,
		QDMA_DBE_ERR_WB_CTXT_RAM_MASK,
		QDMA_GLBL_ERR_RAM_DBE_MASK
	},
	{
		QDMA_DBE_ERR_PFCH_LL_RAM,
		"C2H ST prefetch list RAM double bit ECC error",
		QDMA_OFFSET_RAM_DBE_MASK,
		QDMA_OFFSET_RAM_DBE_STAT,
		QDMA_DBE_ERR_PFCH_LL_RAM_MASK,
		QDMA_GLBL_ERR_RAM_DBE_MASK
	},
	{
		QDMA_DBE_ERR_H2C_PEND_FIFO,
		"H2C pending fifo RAM double bit ECC error",
		QDMA_OFFSET_RAM_DBE_MASK,
		QDMA_OFFSET_RAM_DBE_STAT,
		QDMA_DBE_ERR_H2C_PEND_FIFO_MASK,
		QDMA_GLBL_ERR_RAM_DBE_MASK
	},
	{
		QDMA_DBE_ERR_ALL,
		"All DBE errors",
		QDMA_OFFSET_RAM_DBE_MASK,
		QDMA_OFFSET_RAM_DBE_STAT,
		QDMA_DBE_ERR_ALL_MASK,
		QDMA_GLBL_ERR_RAM_DBE_MASK
	}
};

#endif
