inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������ݵĶ����š�������һ�����������ص����ݵ�
�˶�����������ݳǣ��ٸ���������ؿ����ʹ������ˡ�һ��
���Ʋ��ȵ�ʱ��������ر�Ľ��š�
LONG);
        set("objects", ([
                "/d/kaifeng/npc/guanbing" : 4,
                "/d/beijing/npc/ducha" : 1,
        ]));
	set("no_clean_up", 0);
	set("exits", ([
  		"east" : "/d/suzhou/road4",
  		"west" : __DIR__"yanlingdong2",
	]));
	set("outdoors", "zhongzhou");

	setup();
	replace_program(ROOM);
}
