inherit ROOM;

void create()
{
	set("short", "�ĺ�Ǯׯ");
	set("long", @LONG
�ĺ�Ǯׯ������������Ǯׯ��Ҳ�Ƿǳ����������ֺš��ϰ�������
����һ�޼֣��춥���˺�ѩԴ����ɽ�����ϣ����Ǯׯ������үү��үү
��үү��үү�Ǳ���ʼ����һֱ��������������ǳ��ã���ȫ������
���зֵꡣ�����е���Ʊͨ��ȫ����Ǯׯ���ſڹ���һ������(paizi)��
LONG);
	set("no_clean_up", 0);
	set("exits", ([
		"north" : __DIR__"wroad1",
	]));
        set("item_desc", ([
                "paizi" : @TEXT
     ��Ǯׯ�ṩ���·���
      ��Ǯ        deposit����cun
      ȡǮ        withdraw����qu
      Ǯ�Ҷһ�    convert����duihuan
      ����        check����chazhang
TEXT
        ]) );

        set("objects", ([
                __DIR__"npc/hu" : 1
        ]));

	setup();
	replace_program(ROOM);
}
