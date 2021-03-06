.DEFAULT: all
.PHONY: all clean fclean re clean-dependency fclean-dependency
.SUFFIXES: .c .o

NAME := push_swap

CC ?= clang
RM ?= rm
LD := $(CC)

INC := inc/array.h \
		inc/checks.h \
		inc/chunk_sort.h \
		inc/lifo_stack.h \
		inc/median.h \
		inc/ops.h \
		inc/ovm.h \
		inc/ps_runtime.h \
		inc/san.h \
		inc/sort.h \


CFLAGS ?=
CFLAGS := $(CFLAGS) -Wall -Wextra -Werror -Iinc -Ilibft/inc # -g3 # -fsanitize=address
LDFLAGS := $(LDFLAGS) # -g3 # -fsanitize=address

LIBFT := libft/libft.a

BUILD_TYPE := release

include libft/src/Makefile
include libft/inc/Makefile

LIBFT_SRCS := $(addprefix libft/, $(LIBFT_SRCS))
LIBFT_INCLUDES := $(addprefix libft/, $(LIBFT_INCLUDES))

OBJS := src/main.o \
		src/checks.o \
		src/new_median.o \
		src/new_median_ext.o \
		src/array.o \
		src/array_ext.o \
		src/lifo_stack.o \
		src/lifo_stack_op.o \
		src/ps_runtime.o \
		src/ops_push_swap.o \
		src/ops_rotate.o \
		src/ops_rrotate.o \
		src/ops_target.o \
		src/ops_ntarget.o \
		src/ops_utils.o \
		src/chunk_sort.o \
		src/chunk_sort2.o \
		src/lazy_sort.o \
		src/san.o \
		src/ovm.o \
		src/ovm_optimize.o \
		src/ovm_optimize_merge.o \

all: $(NAME) $(LIBFT) $(OBJS) $(LIBFT_SRCS) $(LIBFT_INCLUDES)

$(NAME): $(LIBFT) $(OBJS) $(LIBFT_SRCS) $(LIBFT_INCLUDES)
	make -C libft/ all
	$(LD) $(LDFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o: %.c $(INC) $(LIBFT_SRCS) $(LIBFT_INCLUDES)
	$(CC) $(CFLAGS) -o $@ -c $<

clean: clean-dependency
	$(RM) -f $(OBJS)

fclean: fclean-dependency
	$(RM) -f $(OBJS)
	$(RM) -f $(NAME)

re: fclean all

debug:	BUILD_TYPE := debug
debug:	all

run:	all
	@# ./$(NAME) "129" "98" "134" "0" "-18" "21" "60" "-66" "50" "-133" "-160" "178" "-88" "-22" "-102" "97" "184" "-96" "179" "172" "108" "-138" "-175" "107" "-113" "169" "-130" "-123" "-127" "-60" "-93" "-11" "-191" "-110" "-25" "-172" "19" "168" "-29" "12" "-19" "-128" "-42" "-111" "7" "-16" "-132" "176" "144" "152" "54" "46" "-10" "-9" "-163" "4" "120" "-27" "-185" "38" "9" "11" "-173" "-14" "156" "-65" "-112" "131" "52" "96" "31" "199" "-61" "-47" "-57" "62" "104" "-45" "8" "195" "6" "-197" "-28" "80" "-52" "99" "-6" "25" "-58" "26" "-153" "-136" "-140" "-126" "143" "-183" "-85" "29" "-154" "65" "56" "185" "196" "33" "146" "137" "-59" "-35" "188" "-150" "-90" "125" "115" "135" "-3" "117" "-53" "-48" "-44" "-156" "-87" "-198" "23" "-108" "110" "82" "-71" "-7" "17" "-69" "-178" "86" "-15" "-75" "-24" "51" "-81" "-186" "-77" "114" "-141" "-196" "58" "-37" "95" "-5" "-103" "-109" "74" "-34" "-155" "167" "-157" "161" "-151" "-176" "-139" "49" "18" "154" "-92" "-67" "-200" "92" "-120" "-70" "133" "121" "79" "111" "-148" "193" "76" "123" "-1" "-51" "190" "174" "35" "-177" "41" "16" "-98" "-31" "-165" "69" "94" "-199" "-89" "53" "-131" "183" "100" "-56" "-55" "-78" "78" "30" "159" "-184" "136" "153" "37" "-162" "-187" "-193" "177" "87" "13" "-134" "-122" "112" "140" "-167" "-189" "160" "-8" "103" "109" "-104" "-79" "44" "142" "-80" "-147" "-171" "-64" "155" "-117" "191" "102" "64" "141" "66" "126" "-39" "34" "170" "72" "-41" "-43" "124" "93" "122" "-50" "-159" "57" "101" "-74" "128" "-116" "138" "81" "88" "-135" "-95" "-12" "-145" "43" "-118" "119" "20" "1" "-26" "-125" "-32" "198" "-82" "165" "71" "48" "-38" "-63" "-76" "200" "45" "194" "-100" "15" "-194" "-73" "-83" "181" "10" "40" "-182" "-195" "-99" "-86" "-40" "-129" "-13" "-72" "32" "-97" "-158" "130" "-94" "68" "24" "36" "-30" "-68" "-190" "3" "-161" "106" "-188" "-46" "166" "118" "70" "67" "-179" "-119" "59" "132" "63" "27" "149" "175" "-166" "-114" "-164" "-149" "150" "85" "77" "-144" "-4" "113" "14" "-181" "84" "-169" "89" "73" "47" "171" "-168" "-152" "-36" "-124" "-180" "55" "-170" "116" "-142" "-192" "186" "-105" "182" "-146" "151" "61" "-174" "28" "-121" "-17" "192" "90" "173" "139" "-21" "-101" "-54" "-20" "180" "-84" "2" "42" "105" "91" "187" "-143" "83" "147" "-137" "-106" "-23" "145" "-107" "189" "-91" "157" "164" "162" "75" "-33" "148" "-62" "163" "22" "-49" "127" "-115" "158" "197" "39" "-2" "5"
	./$(NAME) "129" "98" "134" "0" "-18" "21" "60" "-66" "50" "-133" "-160" "178" "-88" "-22" "-102" "97" "184" "-96" "179" "172" "108"

# DEPENDENCIES TARGET

$(LIBFT):
	make -C libft/ all

clean-dependency:
	make -C libft/ clean

fclean-dependency:
	make -C libft/ fclean
