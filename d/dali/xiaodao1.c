inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
������С������ǰ��Լ��ʮ���ߣ�ֻ������������Ũ���
�죬һ����ȪǶ����䣬������ʯ��Ȫˮ��������������Ǯ��
�ڳ��У����仺�����䣬���������ɸ�£��ص�������˸����
��Ȫˮ�������ر߾����Լ�����ߵĵط���һ�ֿɺϱ�������
���Ȫ�ϣ����Խ���Сͤ��С��������ʮ�����ġ� 
LONG);
	set("outdoors", "dali");
	set("exits", ([
                "northup" : __DIR__"qingxi",
                "south"   : __DIR__"heilongling",
                "west"    : __DIR__"hudiequan",
	]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));
	setup();
	replace_program(ROOM);
}

