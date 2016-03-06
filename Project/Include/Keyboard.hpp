#ifndef __KEYBOARD_HPP
#define __KEYBOARD_HPP

enum EKeyCode
{

	// Control characters
	e_key_NULL = 0,
	e_key_SOH = 1,
	e_key_STX = 2,
	e_key_ETX = 3,
	e_key_EOT = 4,
	e_key_ENQ = 5,
	e_key_ACK = 6,
	e_key_BEL = 7,
	e_key_BS = 8,
	e_key_backspace = e_key_BS,
	e_key_HT = 9,
	e_key_tab = e_key_HT,
	e_key_LF = 10,
	e_key_VT = 11,
	e_key_FF = 12,
	e_key_CR = 13,
	e_key_enter = e_key_CR,
	e_key_SO = 14,
	e_key_SI = 15,
	e_key_DLE = 16,
	e_key_DC1 = 17,
	e_key_DC2 = 18,
	e_key_DC3 = 19,
	e_key_DC4 = 20,
	e_key_NAK = 21,
	e_key_SYN = 22,
	e_key_ETB = 23,
	e_key_CAN = 24,
	e_key_EM = 25,
	e_key_SUB = 26,
	e_key_ESC = 27,
	e_key_escape = e_key_ESC,
	e_key_FS = 28,
	e_key_GS = 29,
	e_key_RS = 30,
	e_key_US = 31,

	// Punctuation 1
	e_key_space = ' ',
	e_key_bang = '!',
	e_key_double_quote = '"',
	e_key_hashtag = '#',
	e_key_dollar = '$',
	e_key_percent = '%',
	e_key_ampersand = '&',
	e_key_quote = '\'',
	e_key_open_parenthesis = '(',
	e_key_close_parenthesis = ')',
	e_key_star = '*',
	e_key_plus = '+',
	e_key_comma = ',',
	e_key_minus = '-',
	e_key_dot = '.',
	e_key_slash = '/',

	// Numbers
	e_key_0 = '0',
	e_key_1,
	e_key_2,
	e_key_3,
	e_key_4,
	e_key_5,
	e_key_6,
	e_key_7,
	e_key_8,
	e_key_9,

	// Punctuation 2
	e_key_column = ':',
	e_key_semicolumn = ';',
	e_key_less_than = '<',
	e_key_equals = '=',
	e_key_greate_rthan = '>',
	e_key_question = '?',
	e_key_at = '@',

	// Uppercase letters
	e_key_A = 'A',
	e_key_B,
	e_key_C,
	e_key_D,
	e_key_E,
	e_key_F,
	e_key_G,
	e_key_H,
	e_key_I,
	e_key_J,
	e_key_K,
	e_key_L,
	e_key_M,
	e_key_N,
	e_key_O,
	e_key_P,
	e_key_Q,
	e_key_R,
	e_key_S,
	e_key_T,
	e_key_U,
	e_key_V,
	e_key_W,
	e_key_X,
	e_key_Y,
	e_key_Z,

	// Punctuation 3
	e_key_open_square = '[',
	e_key_backslash = '\\',
	e_key_close_square = ']',
	e_key_circumflex = '^',
	e_key_underscore = '_',
	e_key_backquote = '`',

	// Lowercase letters
	e_key_a = 'a',
	e_key_b,
	e_key_c,
	e_key_d,
	e_key_e,
	e_key_f,
	e_key_g,
	e_key_h,
	e_key_i,
	e_key_j,
	e_key_k,
	e_key_l,
	e_key_m,
	e_key_n,
	e_key_o,
	e_key_p,
	e_key_q,
	e_key_r,
	e_key_s,
	e_key_t,
	e_key_u,
	e_key_v,
	e_key_w,
	e_key_x,
	e_key_y,
	e_key_z,


	// Punctuation 4
	e_key_open_brace = '{',
	e_key_pipe = '|',
	e_key_clos_ebrace = '}',
	e_key_tild = '~',
	e_key_DEL = 127,
	e_key_delete = e_key_DEL,

	// Extended characters
	e_key_extended_0 = 128,
	e_key_extended_1,
	e_key_extended_2,
	e_key_extended_3,
	e_key_extended_4,
	e_key_extended_5,
	e_key_extended_6,
	e_key_extended_7,
	e_key_extended_8,
	e_key_extended_9,
	e_key_extended_10,
	e_key_extended_11,
	e_key_extended_12,
	e_key_extended_13,
	e_key_extended_14,
	e_key_extended_15,
	e_key_extended_16,
	e_key_extended_17,
	e_key_extended_18,
	e_key_extended_19,
	e_key_extended_20,
	e_key_extended_21,
	e_key_extended_22,
	e_key_extended_23,
	e_key_extended_24,
	e_key_extended_25,
	e_key_extended_26,
	e_key_extended_27,
	e_key_extended_28,
	e_key_extended_29,
	e_key_extended_30,
	e_key_extended_31,
	e_key_extended_32,
	e_key_extended_33,
	e_key_extended_34,
	e_key_extended_35,
	e_key_extended_36,
	e_key_extended_37,
	e_key_extended_38,
	e_key_extended_39,
	e_key_extended_40,
	e_key_extended_41,
	e_key_extended_42,
	e_key_extended_43,
	e_key_extended_44,
	e_key_extended_45,
	e_key_extended_46,
	e_key_extended_47,
	e_key_extended_48,
	e_key_extended_49,
	e_key_extended_50,
	e_key_extended_51,
	e_key_extended_52,
	e_key_extended_53,
	e_key_extended_54,
	e_key_extended_55,
	e_key_extended_56,
	e_key_extended_57,
	e_key_extended_58,
	e_key_extended_59,
	e_key_extended_60,
	e_key_extended_61,
	e_key_extended_62,
	e_key_extended_63,
	e_key_extended_64,
	e_key_extended_65,
	e_key_extended_66,
	e_key_extended_67,
	e_key_extended_68,
	e_key_extended_69,
	e_key_extended_70,
	e_key_extended_71,
	e_key_extended_72,
	e_key_extended_73,
	e_key_extended_74,
	e_key_extended_75,
	e_key_extended_76,
	e_key_extended_77,
	e_key_extended_78,
	e_key_extended_79,
	e_key_extended_80,
	e_key_extended_81,
	e_key_extended_82,
	e_key_extended_83,
	e_key_extended_84,
	e_key_extended_85,
	e_key_extended_86,
	e_key_extended_87,
	e_key_extended_88,
	e_key_extended_89,
	e_key_extended_90,
	e_key_extended_91,
	e_key_extended_92,
	e_key_extended_93,
	e_key_extended_94,
	e_key_extended_95,
	e_key_extended_96,
	e_key_extended_97,
	e_key_extended_98,
	e_key_extended_99,
	e_key_extended_100,
	e_key_extended_101,
	e_key_extended_102,
	e_key_extended_103,
	e_key_extended_104,
	e_key_extended_105,
	e_key_extended_106,
	e_key_extended_107,
	e_key_extended_108,
	e_key_extended_109,
	e_key_extended_110,
	e_key_extended_111,
	e_key_extended_112,
	e_key_extended_113,
	e_key_extended_114,
	e_key_extended_115,
	e_key_extended_116,
	e_key_extended_117,
	e_key_extended_118,
	e_key_extended_119,
	e_key_extended_120,
	e_key_extended_121,
	e_key_extended_122,
	e_key_extended_123,
	e_key_extended_124,
	e_key_extended_125,
	e_key_extended_126,
	e_key_extended_127,

	// Modifier character
	e_key_shift = 256,
	e_key_ctrl,
	e_key_alt,
	e_key_left_shift,
	e_key_left_ctrl,
	e_key_left_alt,
	e_key_right_shift,
	e_key_right_ctrl,
	e_key_right_alt,

	// Special characters
	e_key_f1,
	e_key_f2,
	e_key_f3,
	e_key_f4,
	e_key_f5,
	e_key_f6,
	e_key_f7,
	e_key_f8,
	e_key_f9,
	e_key_f10,
	e_key_f11,
	e_key_f12,
	e_key_left,
	e_key_up,
	e_key_right,
	e_key_down,
	e_key_page_up,
	e_key_page_down,
	e_key_home,
	e_key_end,
	e_key_insert,

	e_key_count // Keep at the end of the enum

};

struct Key
{
	explicit Key(void);
	explicit Key(EKeyCode co, unsigned char ch);
	EKeyCode code;
	unsigned char character;
};

class Keyboard
{

public:

	virtual ~Keyboard(void);

	static void Initialize(void);

	static void UpdateModifiers(void);

	static bool IsShiftPressed(void);
	static bool IsCtrlPressed(void);
	static bool IsAltPressed(void);

	static bool IsShiftStateChanged(void);
	static bool IsCtrlStateChanged(void);
	static bool IsAltStateChanged(void);

	static void SetKeyRepeatEnabled(bool state);

	static void SetKey(EKeyCode key, bool state);
	static bool GetKey(EKeyCode key);

private:

	explicit Keyboard(void);

	static bool s_keys[e_key_count];
	static int s_modifiers;
	static int s_oldModifiers;

protected:

};

#endif // __KEYBOARD_HPP