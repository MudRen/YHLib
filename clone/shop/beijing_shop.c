inherit SHOP;

void create()
{
	set("short", "�۱���");
	set("long", @LONG
������Ǳ��������������ľ۱��ã�������������������
��Ϣ���Գ�����֮�������󷽵����ɡ���������Ļ�����ȴ��
��һ��������Ѿ��ܾ�û���������ˡ�
LONG);
        set("open_long", @LONG
������Ǳ��������������ľ۱��ã�������������������
��Ϣ���Գ�����֮�������󷽵����ɡ���������������ϰ�
���˸�ʽ������������Ŀ�Ļ��
LONG);
	set("no_fight", 1);
	set("no_beg", 1);
	set("owner", "VOID_SHOP");
	set("exits", ([
                "down" : "/d/beijing/majiu",
        ]));
	set("no_steal", 1);
	set("objects", ([
                __DIR__"waiter" : 1,
        ]));
	set("no_clean_up", 0);
	set("shop_type", 0);

	setup();
}
