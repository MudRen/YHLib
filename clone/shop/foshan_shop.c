inherit SHOP;

void create()
{
	set("short", "Ӣ��¥");
	set("long", @LONG
Ӣ��¥���Ƿ�ɽ�����������������ȴ�Ѿ����޸��˱��ˡ�
�������ý�̻Իͣ���ⱦ��ӳ���������ԡ���������Ļ���
��ȴ����һ��������Ѿ��ܾ�û���������ˡ�
LONG);
        set("open_long", @LONG
Ӣ��¥���Ƿ�ɽ�����������������ȴ�Ѿ����޸��˱��ˡ�
�������ý�̻Իͣ���ⱦ��ӳ���������ԡ���������������
����Ϣ�����̻�����к��ſ��ˣ�æ����ͷ�󺹡�
LONG);
	set("no_fight", 1);
	set("no_beg", 1);
	set("owner", "VOID_SHOP");
	set("exits", ([
                "down" : "/d/foshan/majiu",
        ]));
	set("no_steal", 1);
	set("objects", ([
                __DIR__ "waiter" : 1,
        ]));
	set("no_clean_up", 0);
	set("shop_type", 0);

	setup();
}
