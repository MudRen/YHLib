inherit ROOM;

void create()
{
	set("short", "��Ӥ��");
	set("long", @LONG
�߽���Ӥ�ã��㿴����������һЩС���ӣ�һλ���긾Ů�����տ���
��ЩС���ӣ�ԭ�����������˿����ӵĵط�������������Щ����Ϊû��
ʱ���տ��Լ��ĺ��ӣ��Ͱ������͵�����������ר�˿��ܡ���Ӥ�������
��С�����ǵ���޺���������
LONG);
	set("no_clean_up", 0);
	set("exits", ([
  		"north" : __DIR__"eroad3",
	]));
        set("objects", ([
                "/d/beijing/npc/girl2" : 1,
                "/d/beijing/npc/kid1" : 1,
                "/d/beijing/npc/girl4" : 1,
                "/d/beijing/npc/boy2" : 1,
        ]));
	setup();
	replace_program(ROOM);
}
