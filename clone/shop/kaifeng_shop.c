inherit SHOP;

void create()
{
	set("short", "��ׯ");
	set("long", @LONG
�����ǿ�����������ĵ�����ׯ������Ϊ����Ŷ�����
�ڸ��ġ�������װ�ε÷ǳ���������������ȴ����һ����
��һ�Դ�����������Ѿ��ܾ�û���������ˡ�
LONG);
        set("open_long", @LONG
�����ǿ�����������ĵ�����ׯ��������������������
����Ϣ������Ϊ����Ŷ������۵���ƷҲ�Ǳ��һ�������
�����������ϰ����˸�ʽ������������Ŀ�Ļ��
LONG);
	set("no_fight", 1);
	set("no_beg", 1);
	set("owner", "VOID_SHOP");
	set("exits", ([
                "down" : "/d/kaifeng/majiu",
        ]));
	set("no_steal", 1);
	set("objects", ([
                __DIR__"waiter" : 1,
        ]));
	set("no_clean_up", 0);
	set("shop_type", 0);

	setup();
}
