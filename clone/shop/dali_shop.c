inherit SHOP;

void create()
{
	set("short", "���԰");
	set("long", @LONG
�����Ǵ�����������ĵ������԰������ش����ϣ�����
���ġ�������װ�ε÷ǳ�����������������ȴ����һ����
��һ�Դ�����������Ѿ��ܾ�û���������ˡ�
LONG);
        set("open_long", @LONG
�����Ǵ�����������ĵ������԰��������������������
����Ϣ������ش����ϣ����۵���ƷҲ�Ǳ��һ�������
���������ϰ����˸�ʽ������������Ŀ�Ļ��
LONG);
	set("no_fight", 1);
	set("no_beg", 1);
	set("owner", "VOID_SHOP");
	set("exits", ([
                "down" : "/d/dali/majiu",
        ]));
	set("no_steal", 1);
	set("objects", ([
                __DIR__"waiter" : 1,
        ]));
	set("no_clean_up", 0);
	set("shop_type", 0);

	setup();
}
