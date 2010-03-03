/* GSM Radio Signalling Link messages on the A-bis interface 
 * 3GPP TS 08.58 version 8.6.0 Release 1999 / ETSI TS 100 596 V8.6.0 */

/* (C) 2008-2009 by Harald Welte <laforge@gnumonks.org>
 *
 * All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */

#include <osmocore/tlv.h>
#include <osmocore/rsl.h>

void rsl_init_rll_hdr(struct abis_rsl_rll_hdr *dh, uint8_t msg_type)
{
	dh->c.msg_discr = ABIS_RSL_MDISC_RLL;
	dh->c.msg_type = msg_type;
	dh->ie_chan = RSL_IE_CHAN_NR;
	dh->ie_link_id = RSL_IE_LINK_IDENT;
}

const struct tlv_definition rsl_att_tlvdef = {
	.def = {
		[RSL_IE_CHAN_NR]		= { TLV_TYPE_TV },
		[RSL_IE_LINK_IDENT]		= { TLV_TYPE_TV },
		[RSL_IE_ACT_TYPE]		= { TLV_TYPE_TV },
		[RSL_IE_BS_POWER]		= { TLV_TYPE_TV },
		[RSL_IE_CHAN_IDENT]		= { TLV_TYPE_TLV },
		[RSL_IE_CHAN_MODE]		= { TLV_TYPE_TLV },
		[RSL_IE_ENCR_INFO]		= { TLV_TYPE_TLV },
		[RSL_IE_FRAME_NUMBER]		= { TLV_TYPE_FIXED, 2 },
		[RSL_IE_HANDO_REF]		= { TLV_TYPE_TV },
		[RSL_IE_L1_INFO]		= { TLV_TYPE_FIXED, 2 },
		[RSL_IE_L3_INFO]		= { TLV_TYPE_TL16V },
		[RSL_IE_MS_IDENTITY]		= { TLV_TYPE_TLV },
		[RSL_IE_MS_POWER]		= { TLV_TYPE_TV },
		[RSL_IE_PAGING_GROUP]		= { TLV_TYPE_TV },
		[RSL_IE_PAGING_LOAD]		= { TLV_TYPE_FIXED, 2 },
		[RSL_IE_PYHS_CONTEXT]		= { TLV_TYPE_TLV },
		[RSL_IE_ACCESS_DELAY]		= { TLV_TYPE_TV },
		[RSL_IE_RACH_LOAD]		= { TLV_TYPE_TLV },
		[RSL_IE_REQ_REFERENCE]		= { TLV_TYPE_FIXED, 3 },
		[RSL_IE_RELEASE_MODE]		= { TLV_TYPE_TV },
		[RSL_IE_RESOURCE_INFO]		= { TLV_TYPE_TLV },
		[RSL_IE_RLM_CAUSE]		= { TLV_TYPE_TLV },
		[RSL_IE_STARTNG_TIME]		= { TLV_TYPE_FIXED, 2 },
		[RSL_IE_TIMING_ADVANCE]		= { TLV_TYPE_TV },
		[RSL_IE_UPLINK_MEAS]		= { TLV_TYPE_TLV },
		[RSL_IE_CAUSE]			= { TLV_TYPE_TLV },
		[RSL_IE_MEAS_RES_NR]		= { TLV_TYPE_TV },
		[RSL_IE_MSG_ID]			= { TLV_TYPE_TV },
		[RSL_IE_SYSINFO_TYPE]		= { TLV_TYPE_TV },
		[RSL_IE_MS_POWER_PARAM]		= { TLV_TYPE_TLV },
		[RSL_IE_BS_POWER_PARAM]		= { TLV_TYPE_TLV },
		[RSL_IE_PREPROC_PARAM]		= { TLV_TYPE_TLV },
		[RSL_IE_PREPROC_MEAS]		= { TLV_TYPE_TLV },
		[RSL_IE_IMM_ASS_INFO]		= { TLV_TYPE_TLV },
		[RSL_IE_SMSCB_INFO]		= { TLV_TYPE_FIXED, 23 },
		[RSL_IE_MS_TIMING_OFFSET]	= { TLV_TYPE_TV },
		[RSL_IE_ERR_MSG]		= { TLV_TYPE_TLV },
		[RSL_IE_FULL_BCCH_INFO]		= { TLV_TYPE_TLV },
		[RSL_IE_CHAN_NEEDED]		= { TLV_TYPE_TV },
		[RSL_IE_CB_CMD_TYPE]		= { TLV_TYPE_TV },
		[RSL_IE_SMSCB_MSG]		= { TLV_TYPE_TLV },
		[RSL_IE_FULL_IMM_ASS_INFO]	= { TLV_TYPE_TLV },
		[RSL_IE_SACCH_INFO]		= { TLV_TYPE_TLV },
		[RSL_IE_CBCH_LOAD_INFO]		= { TLV_TYPE_TV },
		[RSL_IE_SMSCB_CHAN_INDICATOR]	= { TLV_TYPE_TV },
		[RSL_IE_GROUP_CALL_REF]		= { TLV_TYPE_TLV },
		[RSL_IE_CHAN_DESC]		= { TLV_TYPE_TLV },
		[RSL_IE_NCH_DRX_INFO]		= { TLV_TYPE_TLV },
		[RSL_IE_CMD_INDICATOR]		= { TLV_TYPE_TLV },
		[RSL_IE_EMLPP_PRIO]		= { TLV_TYPE_TV },
		[RSL_IE_UIC]			= { TLV_TYPE_TLV },
		[RSL_IE_MAIN_CHAN_REF]		= { TLV_TYPE_TV },
		[RSL_IE_MR_CONFIG]		= { TLV_TYPE_TLV },
		[RSL_IE_MR_CONTROL]		= { TLV_TYPE_TV },
		[RSL_IE_SUP_CODEC_TYPES]	= { TLV_TYPE_TLV },
		[RSL_IE_CODEC_CONFIG]		= { TLV_TYPE_TLV },
		[RSL_IE_RTD]			= { TLV_TYPE_TV },
		[RSL_IE_TFO_STATUS]		= { TLV_TYPE_TV },
		[RSL_IE_LLP_APDU]		= { TLV_TYPE_TLV },
		[RSL_IE_SIEMENS_MRPCI]		= { TLV_TYPE_TV },
		[RSL_IE_IPAC_PROXY_UDP]		= { TLV_TYPE_FIXED, 2 },
		[RSL_IE_IPAC_BSCMPL_TOUT]	= { TLV_TYPE_TV },
		[RSL_IE_IPAC_REMOTE_IP]		= { TLV_TYPE_FIXED, 4 },
		[RSL_IE_IPAC_REMOTE_PORT]	= { TLV_TYPE_FIXED, 2 },
		[RSL_IE_IPAC_RTP_PAYLOAD]	= { TLV_TYPE_TV },
		[RSL_IE_IPAC_LOCAL_PORT]	= { TLV_TYPE_FIXED, 2 },
		[RSL_IE_IPAC_SPEECH_MODE]	= { TLV_TYPE_TV },
		[RSL_IE_IPAC_LOCAL_IP]		= { TLV_TYPE_FIXED, 4 },
		[RSL_IE_IPAC_CONN_ID]		= { TLV_TYPE_FIXED, 2 },
		[RSL_IE_IPAC_RTP_CSD_FMT]	= { TLV_TYPE_TV },
		[RSL_IE_IPAC_RTP_JIT_BUF]	= { TLV_TYPE_FIXED, 2 },
		[RSL_IE_IPAC_RTP_COMPR]		= { TLV_TYPE_TV },
		[RSL_IE_IPAC_RTP_PAYLOAD2]	= { TLV_TYPE_TV },
		[RSL_IE_IPAC_RTP_MPLEX]		= { TLV_TYPE_FIXED, 8 },
		[RSL_IE_IPAC_RTP_MPLEX_ID]	= { TLV_TYPE_TV },
	},
};

/* encode channel number as per Section 9.3.1 */
uint8_t rsl_enc_chan_nr(uint8_t type, uint8_t subch, uint8_t timeslot)
{
	uint8_t ret;

	ret = (timeslot & 0x07) | type;

	switch (type) {
	case RSL_CHAN_Lm_ACCHs:
		subch &= 0x01;
		break;
	case RSL_CHAN_SDCCH4_ACCH:
		subch &= 0x07;
		break;
	case RSL_CHAN_SDCCH8_ACCH:
		subch &= 0x07;
		break;
	default:
		/* no subchannels allowed */
		subch = 0x00;
		break;
	}
	ret |= (subch << 3);

	return ret;
}

/* FIXME: convert to value_string */
static const char *rsl_err_vals[0xff] = {
	[RSL_ERR_RADIO_IF_FAIL] =	"Radio Interface Failure",
	[RSL_ERR_RADIO_LINK_FAIL] =	"Radio Link Failure",
	[RSL_ERR_HANDOVER_ACC_FAIL] =	"Handover Access Failure",
	[RSL_ERR_TALKER_ACC_FAIL] =	"Talker Access Failure",
	[RSL_ERR_OM_INTERVENTION] =	"O&M Intervention",
	[RSL_ERR_NORMAL_UNSPEC] =	"Normal event, unspecified",
	[RSL_ERR_T_MSRFPCI_EXP] =	"Siemens: T_MSRFPCI Expired",
	[RSL_ERR_EQUIPMENT_FAIL] =	"Equipment Failure",
	[RSL_ERR_RR_UNAVAIL] =		"Radio Resource not available",
	[RSL_ERR_TERR_CH_FAIL] =	"Terrestrial Channel Failure",
	[RSL_ERR_CCCH_OVERLOAD] =	"CCCH Overload",
	[RSL_ERR_ACCH_OVERLOAD] =	"ACCH Overload",
	[RSL_ERR_PROCESSOR_OVERLOAD] =	"Processor Overload",
	[RSL_ERR_RES_UNAVAIL] =		"Resource not available, unspecified",
	[RSL_ERR_TRANSC_UNAVAIL] =	"Transcoding not available",
	[RSL_ERR_SERV_OPT_UNAVAIL] =	"Service or Option not available",
	[RSL_ERR_ENCR_UNIMPL] =		"Encryption algorithm not implemented",
	[RSL_ERR_SERV_OPT_UNIMPL] =	"Service or Option not implemented",
	[RSL_ERR_RCH_ALR_ACTV_ALLOC] =	"Radio channel already activated",
	[RSL_ERR_INVALID_MESSAGE] =	"Invalid Message, unspecified",
	[RSL_ERR_MSG_DISCR] =		"Message Discriminator Error",
	[RSL_ERR_MSG_TYPE] =		"Message Type Error",
	[RSL_ERR_MSG_SEQ] =		"Message Sequence Error",
	[RSL_ERR_IE_ERROR] =		"General IE error",
	[RSL_ERR_MAND_IE_ERROR] =	"Mandatory IE error",
	[RSL_ERR_OPT_IE_ERROR] =	"Optional IE error",
	[RSL_ERR_IE_NONEXIST] =		"IE non-existent",
	[RSL_ERR_IE_LENGTH] =		"IE length error",
	[RSL_ERR_IE_CONTENT] =		"IE content error",
	[RSL_ERR_PROTO] =		"Protocol error, unspecified",
	[RSL_ERR_INTERWORKING] =	"Interworking error, unspecified",
};

const struct value_string rsl_rlm_cause_strs[] = {
	{ RLL_CAUSE_T200_EXPIRED,	"Timer T200 expired (N200+1) times" },
	{ RLL_CAUSE_REEST_REQ,		"Re-establishment request" },
	{ RLL_CAUSE_UNSOL_UA_RESP,	"Unsolicited UA response" },
	{ RLL_CAUSE_UNSOL_DM_RESP,	"Unsolicited DM response" },
	{ RLL_CAUSE_UNSOL_DM_RESP_MF,	"Unsolicited DM response, multiple frame" },
	{ RLL_CAUSE_UNSOL_SPRV_RESP,	"Unsolicited supervisory response" },
	{ RLL_CAUSE_SEQ_ERR,		"Sequence Error" },
	{ RLL_CAUSE_UFRM_INC_PARAM,	"U-Frame with incorrect parameters" },
	{ RLL_CAUSE_SFRM_INC_PARAM,	"S-Frame with incorrect parameters" },
	{ RLL_CAUSE_IFRM_INC_MBITS,	"I-Frame with incorrect use of M bit" },
	{ RLL_CAUSE_IFRM_INC_LEN,	"I-Frame with incorrect length" },
	{ RLL_CAUSE_FRM_UNIMPL,		"Fraeme not implemented" },
	{ RLL_CAUSE_SABM_MF,		"SABM command, multiple frame established state" },
	{ RLL_CAUSE_SABM_INFO_NOTALL,	"SABM frame with information not allowed in this state" },
	{ 0,				NULL },
};

const char *rsl_err_name(uint8_t err)
{
	if (rsl_err_vals[err])
		return rsl_err_vals[err];
	else
		return "unknown";
}

/* Section 3.3.2.3 TS 05.02. I think this looks like a table */
int rsl_ccch_conf_to_bs_cc_chans(int ccch_conf)
{
	switch (ccch_conf) {
	case RSL_BCCH_CCCH_CONF_1_NC:
		return 1;
	case RSL_BCCH_CCCH_CONF_1_C:
		return 1;
	case RSL_BCCH_CCCH_CONF_2_NC:
		return 2;
	case RSL_BCCH_CCCH_CONF_3_NC:
		return 3;
	case RSL_BCCH_CCCH_CONF_4_NC:
		return 4;
	default:
		return -1;
	}
}

/* Section 3.3.2.3 TS 05.02 */
int rsl_ccch_conf_to_bs_ccch_sdcch_comb(int ccch_conf)
{
	switch (ccch_conf) {
	case RSL_BCCH_CCCH_CONF_1_NC:
		return 0;
	case RSL_BCCH_CCCH_CONF_1_C:
		return 1;
	case RSL_BCCH_CCCH_CONF_2_NC:
		return 0;
	case RSL_BCCH_CCCH_CONF_3_NC:
		return 0;
	case RSL_BCCH_CCCH_CONF_4_NC:
		return 0;
	default:
		return -1;
	}
}