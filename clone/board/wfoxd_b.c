#include <ansi.h> 
inherit BULLETIN_BOARD;

void create()
{
        set_name(HIR "��������־��"NOR+HIW"���԰�" NOR, ({ "board" }) );
        set("location", "/d/city/wfoxd");
        set("board_id", "wfoxd_b");
        set("long", "����ǡ�������־�������԰壬�ҹ�ˮɱ���⡣\n" );
        setup();
        set("capacity", 1000);
        replace_program(BULLETIN_BOARD);
}

