#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_read", "see");
}

void create()
{
        set_name( YEL "ͭ��" NOR, ({"tong pai"}));

        set("unit", "��");
        set("long", YEL "����һ�����ķ�����ͭ��,�������:��ǧ���򶾡��ĸ����֡�\n" NOR
                    "ͭ�Ʊ���������һЩϸϸ�Ļ��ƣ���Ҫ��ϸ��(see)������ǿ�������\n" );
        set("value", 50);
        set_weight(200);
        
        setup();
}

int do_read(string arg)
{
        return notify_fail(YEL "                      \n"
"                                   ^                 \n"
"                                @@^ ^     ^          \n"
"                                 ^ ^ ^   ^ ^@@@      \n"
"                              @@@@^ ^ ^ ^ ^ ^        \n"
"                               ^ ^ ^ ^ ^ ^ ^ ^       \n"
"                              ^ ^ ^ ^ ^ ^ ^ ^ ^      \n"
"                             ^ ^ ^ ^O^ ^O^ ^O^ ^     \n"
"                            ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^    \n"
"                           ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^   \n"
"                          ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^ ^  \n" NOR );
}


