inherit ROOM;

void create()
{
        set("short", "��Ժ���");
        set("long", @LONG
��������Ժ��ͼ��ݣ�����������һ����Ⱦ�����ϵ����
���������е������ǵ���ѡ����¼�������еķ�����������
����ġ�ңԶĥ��ȥ�Ĵ�˵��
LONG);
        set("item_desc", ([
            "shelf" : "�˴��Ѿ������Ų���ˡ�\n",
        ]));
        set("exits", ([
            "down" : __DIR__"shuyuan",
        ]));
	set("no_clean_up", 0);
        setup();

        replace_program(ROOM);
}

