// Room: /d/quanzhou/qzroad1.c
// Date: Maay 7, 96   Jay

inherit BUILD_ROOM; 

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
������һ��ɽ·�ϡ�ʱֵ���գ�·�Ե�ɽ���Ͽ����˽��ɫ���Ͳ˻���
LONG );
	set("exits", ([
		"northwest" : "/d/taishan/yidao1",
        "south" : __DIR__"qzroad2",
        "xhmg"  : "/data/room/iliilil/dayuan",
	]));
	set("outdoors", "quanzhou");
	setup();
}

