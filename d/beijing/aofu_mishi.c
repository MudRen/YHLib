#include <ansi.h>
inherit ROOM;

#define BISHOU  "/clone/lonely/bishou"
#define BAOJIA  "/clone/lonely/baojia"

void create()
{
        object ob1, ob2;

        ob1 = find_object(BISHOU);
        if (! ob1) ob1 = load_object(BISHOU);

        ob2 = find_object(BAOJIA);
        if (! ob2) ob2 = load_object(BAOJIA);

        set("short","��������");
        set("long", @LONG
���������ݸ������ң����������ƺ�Ҳû�����ʲô�ر�
�ı�������Χ������ģ���Ϊ��ɭ�ֲ���
LONG);
        set("exits", ([
                "up" :  __DIR__"aofu_shufang",
        ]));
        set("objects", ([
        ]));

        if (! environment(ob1))
               ob1->move(this_object());

        if (! environment(ob2))
               ob2->move(this_object());

        setup();
        replace_program(ROOM);
}
