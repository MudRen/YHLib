//ROOM: /d/yanziwu/shuwu.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ī����");
        set("long",@LONG
����һ�ܼ������ɵ������ǽ����������ϰ����˾�ʷ
�伮��������������һ����������������㱸����īֽ��һӦ
��ȫ��ǽ�Ϲ���һ������(tiaofu)������������Ľ�ݹ��ӳ���
�������д�֡�
LONG );
        set("exits", ([
            "east" : __DIR__"lanyue",
            "north": __DIR__"canheju",
            "south": __DIR__"shangyu",
        ]));

        set("item_desc",([
                          "tiaofu" : HIR "
               �������������
               �����޼�����̶��
               ����δ�������ϣ�
               �������п�Ц̸��\n\n" HIG 
"��������ʼ�վ����������������������ʲô����һ������һʱ���벻������\n\n" NOR,
        ]));
        
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
