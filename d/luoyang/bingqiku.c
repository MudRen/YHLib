inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ǳ����⣬�������������������ۻ����ҡ��������������𹿰���
�󵶡��������ڰ����̵����̽����̹�����ɫ�����ı���Ӧ�о��У���һ
ʱ��֪����ʲô�á�
LONG);
	set("no_clean_up", 0);
	set("exits", ([
  		"south" : __DIR__"bingyin",
	]));
        set("objects", ([
                "/clone/weapon/changjian" : 2,
                "/clone/weapon/gangdao" : 2,
                "/clone/weapon/dagger" : 2,
        ]));

	setup();
	replace_program(ROOM);
}
