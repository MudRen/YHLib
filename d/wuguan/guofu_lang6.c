inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���Ǹ����ȣ�����ͨ����Ϣ�ң���������Ʒ�������ﾲ��
�ĵģ�������·��Ҳ��С������ġ����³��ű�����Ϣ������
����Ϣ���ˡ�
LONG);
        set("no_fight", 1);
        set("exits", ([
               "north" : __DIR__"guofu_woshi1",
               "south" : __DIR__"guofu_wupinfang",
        ]));
        setup();
        replace_program(ROOM);
}
