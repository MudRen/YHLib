#include <ansi.h>
inherit RIVER;

void create()
{
        set("short", "������");
        set("long", @LONG
�˴�һƬ«έ�����״����ֳ�һ�����룬��С��ֻ������
�����⻨��Ҷ��������ˮ�� (river)��ͨ�˴�ɴ˿ɳ˴���
�������롣����ϵ��βС�ۡ�����ԶԶ����ȥ�и����ӡ�
LONG);
        set("arrive_room", "/d/yanziwu/hupan");
        set("exits", ([
                "east"      : __DIR__"pindi",
	        "northdown" : __DIR__"muti",
        ]));
        set("resource/fish", ({ "/clone/fish/liyu",
                                "/clone/fish/jiyu",
                                "/clone/fish/qingyu",
                                "/clone/fish/caoyu", }));

        set("outdoors", "yanziwu");
        replace_program(RIVER);
}
