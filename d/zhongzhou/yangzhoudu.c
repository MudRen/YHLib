#include <ansi.h>
inherit RIVER;

void create()
{
  	set ("short", "���ݶ�");
  	set ("long", @LONG
������ͨ�����ݳǵĶɿڣ���ǰ��Ĺ������� (river)��
�����������۾����������ɴ��������������Ͼ������ݸ�����
��ͣ��ЩС��������һ��С·ͨ�����ݵ����š�
LONG);

        set("arrive_room", "/d/zhongzhou/zhongzhoudu");
  	set("exits", ([
  		"north" : "/d/city/ximen",
	]));
        set("objects", ([
                CLASS_D("lingxiao") + "/shipopo" : 1,
        ]));
        set("resource/fish", ({ "/clone/fish/liyu",
                                "/clone/fish/jiyu",
                                "/clone/fish/qingyu",
                                "/clone/fish/caoyu", }));

  	set("outdoors", "city");
        setup();
        replace_program(RIVER);
}