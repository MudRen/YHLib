#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", GRN "�ϼ�" NOR);
        set("long", @LONG
ת��һ��С�䣬��Ȼ��ǰһ�̣���ǰ��һƬ�ܴ�Ĺϼܡ��ڸߴ��ľ��
�ԣ���ֲ��һЩ�߲˺͹��࣬�������Ѿ������˸��ָ�����ֲ���ï�ܵ�
Ҷ���У����¸����Ѿ�����Ĺ�ʵ��˿�ϣ���ϣ���«��������һЩ�в���
���ƵĹϹ�Ҳ���������С�
LONG    );
        set("exits", ([
                "southeast" : __DIR__"shuijing",
                "west" : __DIR__"guangchang",
        ]));

        set("objects", ([
                CLASS_D("tiezhang") + "/qiuqianzhang" : 1,
        ]));

        set("no_clean_up", 0);
        set("hulu_count", 5);
        set("outdoors", "tiezhang");

        setup();
}
