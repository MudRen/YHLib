#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name(HIY "����ƽ��" NOR, ({ "wall" }) );
        set("location", "/d/wizard/wizard_room");
        set("board_id", "wiz_b");
        set("long", HIY "���ǽ�Ͽ�����ϣ��Źֵ����ģ�Ҳ��֪��������Щʲô��\n" NOR);
        setup();
        set("capacity", 1000);
        replace_program(BULLETIN_BOARD);
}
