#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ɽɽ��");
        set("long", @LONG
������ȫ��̿�ɽ��ʦ���������˾��޵�ɽ�������䲻��
��ȴ���õú������£����ƴ��˼ҵĿ���һ��������������
�Ÿ���(hua)�����β輸���ܾ��¡�
LONG);
        set("exits", ([
                "out" : __DIR__"xiaolu3",
        ]));
        set("item_desc", ([
        	"hua": YEL "\n������һ�������ʿ�ı�Ӱ��������ʲô��"
                       "ò�����е���һ��\nָ���죬�������š�" HIR "��"
                       "������" NOR + YEL "�������֡�\n" NOR,
        ]) );

        set("objects", ([
                CLASS_D("quanzhen") + "/wang" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
