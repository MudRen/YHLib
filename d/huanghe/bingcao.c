inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������Ӫ��ˮ�����ϣ�ƽʱ�˼��������򵱵�ɳĮ�ﳤ
��һ�������ҩ�ݡ����ݶ���������˵����ҩ���ܽ�ٶ�����
��ż�����������ֲݣ��������ж����û����ΪΣ�ա�
LONG);
	set("exits", ([
		"southwest" : __DIR__"shixiazi",
		"northeast" : __DIR__"yinpanshui",
	]));
	set("objects", ([
		"/clone/worm/qianjiewugong" : 1,
	]));
	set("outdoors", "huanghe");
	setup();
	replace_program(ROOM);
}

