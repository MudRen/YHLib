
inherit ROOM;

void create()
{
        set("short", "�չ���");
        set("long", @LONG
����һ��λ�����ɽ�µ�С�������ź��д�� "�չ���" 
�������֡���춴�����������ɽ�ıؾ�֮·����������οͶ�
���ڴ������Ϣ��Ҳ��˴˴����Ҳ��Ϊ��ʢ����ǰ�ļ�����
���£�����һ��ʯ��(shibei)�������챻��Χ�ĳ��ݸ������ˡ�
��������һ��С·.
LONG
        );
        set("outdoors", "quanzhen");
        set("exits", ([
                "west" : __DIR__"shanlu13",
        ]));

        setup();
        replace_program(ROOM);
}
