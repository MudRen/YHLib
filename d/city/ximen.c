inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", "����");
	set("long", @LONG
���������ݳǵ������ţ�����ǰ�����⵽���˵Ĺ�����
���Ե���Щ�ưܡ��������Ϸ�����ǿǿ�����ϳ������š�����
���֣���ǽ�����ż���ͨ����ʾ(gaoshi)���������ﷸ������
��ıؾ�֮�أ��ٱ��ǽ䱸ɭ�ϣ��������ͽ�ס�������ʡ���
ֱ����ʯ���������������졣�����ǽ��⣬����ġ�����
�ġ���·�ģ����˴Ҵҡ������ǳ���ϱ��ǹ�������������
��һ��СС�Ķɿڣ�����ͨ�����ݸ���
LONG);
        set("outdoors", "city");
	set("item_desc", ([
		"gaoshi" : (: look_gaoshi :),
	]));

	set("exits", ([
		"east"  : __DIR__"xidajie2",
		"west"  : __DIR__"ximenroad",
		"south" : "/d/zhongzhou/yangzhoudu",
	]));
        set("objects", ([
                "/d/beijing/npc/ducha" : 1,
                __DIR__"npc/bing" : 4,
                "/d/mingjiao/npc/fenggongying" : 1,
                "/clone/npc/walker" : 1,
        ]));
	setup();

        replace_program(ROOM);
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n����֪��\n��ҩ��\n";
}

