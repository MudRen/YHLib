inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������������ϣ��е�����Ľ���Ҫ�ȱ𴦵ĸɾ������ࡣ
�����Ϊ�������š���Ӫ���ܱ�����Ե�ʣ������Ƕ�ϲ��ס��
������߾����ĵ�û�м������ˣ������������š��ϱ�����
��ݣ�������һ����լԺ����ǰ������һЩ�л��ӡ�
LONG);
        set("outdoors", "city");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"xidajie1",
		"south" : __DIR__"wuguan",
		"west"  : __DIR__"ximen",
		"north" : __DIR__"ma_damen",
	]));

        set("objects", ([
                "/d/gaibang/npc/1dai" : 1 + random(2),
        ]));

	setup();
	replace_program(ROOM);
}

