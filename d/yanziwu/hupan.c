#include <ansi.h>
inherit RIVER;

void create()
{
         set("short", "̫������");
         set("long", @LONG
̫��������֮�䡣���������������֮ˮ�����ڴˣ�����
�����ų������������ (river)����Ψ������Զ��������
�Ա̣���ʮ����Դ�ͦ����������ǧ�겨��֮�У�ʹ���Ľ��
��ֱ�����쳤Х�����ܱ��ϲ�֡�
LONG);
        set("arrive_room", "/d/yanziwu/bozhou");
        set("exits", ([
                "northeast" : "/d/suzhou/road5",
        ]));
        set("objects", ([  
                __DIR__"npc/yufu" : 1,
        ]));  

        set("resource/fish", ({ "/clone/fish/liyu",
                                "/clone/fish/jiyu",
                                "/clone/fish/qingyu",
                                "/clone/fish/caoyu", }));

        set("outdoors", "yanziwu");
        setup();
        replace_program(RIVER);
}
