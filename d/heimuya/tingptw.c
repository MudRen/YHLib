inherit ROOM;
 
void create()
{
        set("short", "������ƫ��");
        set("long",@LONG
ƫ�����õ���Ϊ���ţ�˿��û�������ϵ��������ա�һ��
��ľ���������и���񣬹�����˸�ʽ�������顣ǽ�Ϲ��ż�
���ֻ���
LONG);
        set("exits", ([
            	"east"   : __DIR__"tian1",
        ]));
        setup();
        replace_program(ROOM);
}
